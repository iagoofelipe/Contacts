#include "contactsform.h"
#include "ui_contactsform.h"

#include <QMessageBox>

ContactsForm::ContactsForm(AppModel *model, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContactsForm)
    , model(model)
{
    ui->setupUi(this);

    layout = new QVBoxLayout(ui->widContent);
    auto values = model->getContacts();

    // connecting events
    connect(ui->btnAdd, &QPushButton::clicked, this, &ContactsForm::newRequired);
    connect(model, &AppModel::contactsChanged, this, &ContactsForm::setContacts);
    connect(ui->btnSearch, &QPushButton::clicked, this, &ContactsForm::on_btnSearch_clicked);
    connect(ui->btnEdit, &QPushButton::clicked, this, &ContactsForm::on_btnEdit_clicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &ContactsForm::on_btnDelete_clicked);
    connect(ui->btnUnselect, &QPushButton::clicked, this, [&] { clearSelections(); });
    connect(ui->btnDetails, &QPushButton::clicked, this, &ContactsForm::on_btnDetails_clicked);
    connect(ui->lineSearch, &QLineEdit::returnPressed, ui->btnSearch, &QPushButton::click);

    if (!values.empty())
        setContacts(values);

    ui->btnEdit->hide();
    ui->btnDelete->hide();
    ui->btnUnselect->hide();
    ui->btnDetails->hide();
}

ContactsForm::~ContactsForm()
{
    delete ui;
}

void ContactsForm::setContacts(const ContactMap& contacts)
{
    int count = contacts.count();
    qDebug() << "setting contacts data," << count << "value(s)";

    // cleaning all current values
    if(!widgets.empty()) {
        for(const auto wid : std::as_const(widgets)) {
            wid->deleteLater();
        }

        widgets.clear();
    }

    if(spacer) {
        layout->removeItem(spacer);
        spacer = nullptr;
    }

    clearSelections(false);

    if(contacts.empty())
        return;

    QMap<QChar, QList<int>> idsByLetter;
    model->getLetters(contacts, idsByLetter);

    QMapIterator<QChar, QList<int>> it(idsByLetter);

    while(it.hasNext()) {
        it.next();
        auto letter = it.key();
        auto ids = it.value();

        auto label = new QLabel(letter, ui->widContent);
        auto line = new QFrame(ui->widContent);
        QFont font;

        font.setPointSize(15);
        label->setFont(font);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        layout->addWidget(label);
        layout->addWidget(line);
        widgets.append(label);
        widgets.append(line);

        for(int id : ids) {
            Contact contact = contacts[id];

            auto check = new QCheckBox(contact.name, ui->widContent);
            check->setProperty("id", contact.id);
            connect(check, &QCheckBox::checkStateChanged, this, &ContactsForm::on_checkBox_checkStateChanged);

            layout->addWidget(check);
            widgets.append(check);
        }
    }

    layout->addItem(spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

void ContactsForm::clearSelections(bool uncheck)
{
    if(uncheck)
        for(const auto& check : std::as_const(selectedWidgets)) {
            check->blockSignals(true);
            check->setChecked(false);
            check->blockSignals(false);
        }

    selectedWidgets.clear();
    selectedIds.clear();
    ui->btnEdit->hide();
    ui->btnDelete->hide();
    ui->btnUnselect->hide();
    ui->btnDetails->hide();
}

void ContactsForm::on_btnSearch_clicked()
{
    const QString value = ui->lineSearch->text();

    qDebug() << "searching for " << value;
    ContactMap contacts;

    model->getFiltered(value, contacts);
    setContacts(contacts);
}

void ContactsForm::on_btnEdit_clicked() {
    int id = *selectedIds.begin();
    qDebug() << "dispatching event editRequired, ID" << id;

    emit editRequired(id);
}

void ContactsForm::on_btnDelete_clicked() {
    size_t size = selectedIds.size();
    QString msg = "Would you like to delete ";
    msg += std::to_string(size);
    msg += size == 1? "contact?" : "contacts?";

    QMessageBox *box = new QMessageBox(QMessageBox::Icon::Question, "Confirm delete", msg, QMessageBox::Ok | QMessageBox::Cancel, this);
    ;

    if(QMessageBox::Cancel == box->exec())
        return;

    emit deleteRequired({selectedIds.begin(), selectedIds.end()});
}

void ContactsForm::on_checkBox_checkStateChanged(Qt::CheckState state) {
    QCheckBox* obj = qobject_cast<QCheckBox*>(sender());
    int id = obj->property("id").toInt();

    if(state == Qt::CheckState::Checked) {
        selectedIds.insert(id);
        selectedWidgets.insert(obj);

    } else {
        selectedIds.erase(id);
        selectedWidgets.erase(obj);
    }

    size_t count = selectedIds.size();

    if(!count) { // count 0
        ui->btnEdit->hide();
        ui->btnDelete->hide();
        ui->btnDetails->hide();
        ui->btnUnselect->hide();

    } else if(count == 1) { // count 1
        ui->btnEdit->show();
        ui->btnDetails->show();

    } else { // count > 1
        ui->btnEdit->hide();
        ui->btnDetails->hide();
    }

    if(count >= 1) {
        ui->btnDelete->show();
        ui->btnUnselect->show();
    }
}

void ContactsForm::on_btnDetails_clicked() {
    int id = *selectedIds.begin();
    qDebug() << "dispatching event detailsRequired, ID" << id;

    emit detailsRequired(id);
}

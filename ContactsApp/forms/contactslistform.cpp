#include "contactslistform.h"
#include "ui_contactslistform.h"

ContactsListForm::ContactsListForm(ContactsListModel *model, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContactsListForm)
    , model(model? model : new ContactsListModel{this})
    , spacer(nullptr)
{
    ui->setupUi(this);
    this->model->clearFilter();

    layout = new QVBoxLayout(ui->widList);
    ContactsList *values = this->model->getContacts();

    // connecting events
    connect(ui->btnNew, &QPushButton::clicked, this, &ContactsListForm::newContactRequired);
    connect(this->model, &ContactsListModel::contactsChanged, this, &ContactsListForm::setContacts);
    connect(ui->btnSearch, &QPushButton::clicked, this, &ContactsListForm::on_btnSearch_clicked);
    connect(ui->lineSearch, &QLineEdit::returnPressed, ui->btnSearch, &QPushButton::click);

    if (!values->empty()) setContacts(values);
}

ContactsListForm::~ContactsListForm()
{
    delete ui;
}

ContactsListModel* ContactsListForm::getModel() { return model; }

void ContactsListForm::setContacts(ContactsList *values)
{
    int count = values->count();
    qDebug() << "setting contacts data," << count << "value(s)";

    // cleaning all current values
    for(const auto wid : std::as_const(widgets)) {
        wid->deleteLater();
    }

    widgets.clear();

    if(spacer) {
        layout->removeItem(spacer);
        spacer = nullptr;
    }

    if(values->empty())
        return;

    const QList<QChar> letters = model->getLetters();
    int index = 0;

    for(const auto& letter : letters) {
        auto label = new QLabel(letter, ui->widList);
        QFont font;

        font.setPointSize(15);
        label->setFont(font);
        layout->addWidget(label);
        widgets.append(label);

        for(; index < count; index++) {
            Contact *contact = &(*values)[index];

            if(!contact->name.startsWith(letter))
                break;

            auto labelName = new QLabel(contact->name, ui->widList);

            layout->addWidget(labelName);
            widgets.append(labelName);
        }
    }

    layout->addItem(spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

void ContactsListForm::on_btnSearch_clicked()
{
    const QString value = ui->lineSearch->text();
    qDebug() << "searching for " << value;

    if(value.isEmpty()) {
        model->clearFilter();
        return;
    }

    model->setFilter(value);
}

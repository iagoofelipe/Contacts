#include "contactmanagementform.h"
#include "ui_contactmanagementform.h"

#include <QMessageBox>

QString ContactManagementForm::TitleModeNew = "Add Contact";
QString ContactManagementForm::TitleModeEdit = "Edit Contact";
QString ContactManagementForm::TitleModeDisplay = "Contact Detail";

ContactManagementForm::ContactManagementForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContactManagementForm)
    , contactId(-1)
{
    ui->setupUi(this);
    setMode(New);

    connect(ui->btnBack, &QPushButton::clicked, this, &ContactManagementForm::backRequired);
    connect(ui->btnClear, &QPushButton::clicked, this, &ContactManagementForm::clear);
    connect(ui->btnSave, &QPushButton::clicked, this, &ContactManagementForm::on_btnSave_clicked);
}

ContactManagementForm::~ContactManagementForm()
{
    delete ui;
}

void ContactManagementForm::setMode(Modes mode)
{
    if(currentMode == mode)
        return;

    QString title;
    bool editable;

    switch (mode) {
    case Display:
        title = TitleModeDisplay;
        editable = false;

        ui->btnClear->hide();
        ui->btnSave->hide();
        break;

    case New:
        title = TitleModeNew;
        editable = true;

        ui->btnClear->show();
        ui->btnSave->show();

        break;

    case Edit:
        title = TitleModeEdit;
        editable = true;

        ui->btnClear->show();
        ui->btnSave->show();
        break;
    }

    ui->labelTitle->setText(title);

    ui->lineName->setReadOnly(!editable);
    ui->linePhone->setReadOnly(!editable);
    ui->lineEmail->setReadOnly(!editable);

    clear();
}

void ContactManagementForm::setMode(Modes mode, const Contact& c)
{
    setMode(mode);

    contactId = c.id;
    ui->lineName->setText(c.name);
    ui->linePhone->setText(c.phone);
    ui->lineEmail->setText(c.email);
}

void ContactManagementForm::clear()
{
    ui->lineName->clear();
    ui->linePhone->clear();
    ui->lineEmail->clear();
}

void ContactManagementForm::on_btnSave_clicked()
{
    const QString
        name = ui->lineName->text(),
        phone = ui->linePhone->text(),
        email = ui->lineEmail->text();

    if(name.contains(",") || phone.contains(",") || email.contains(",")) {
        auto box = new QMessageBox(QMessageBox::Icon::Warning, "Invalid Entry", "Entry must not contain \",\"", QMessageBox::NoButton, this);
        box->exec();
        return;
    }

    if(name.isEmpty()) {
        auto box = new QMessageBox(QMessageBox::Icon::Warning, "Invalid Entry", "Name must not be empty", QMessageBox::NoButton, this);
        box->exec();
        return;
    }

    emit saveRequired({ contactId, name, phone, email });

    contactId = -1;
    clear();
}

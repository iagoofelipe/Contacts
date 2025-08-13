#include "newcontactform.h"
#include "ui_newcontactform.h"

#include <QIntValidator>

NewContactForm::NewContactForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NewContactForm)
{
    ui->setupUi(this);

    // setting up components
    ui->linePhoneNumber->setValidator(new QIntValidator);

    // connecting events
    connect(ui->btnClear, &QPushButton::clicked, this, &NewContactForm::on_btnClear_clicked);
    connect(ui->btnSave, &QPushButton::clicked, this, &NewContactForm::on_btnSave_clicked);
}

NewContactForm::~NewContactForm()
{
    delete ui;
}

void NewContactForm::on_btnClear_clicked() {
    ui->lineName->clear();
    ui->lineEmail->clear();
    ui->linePhoneNumber->clear();
}

void NewContactForm::on_btnSave_clicked() {
    emit saveRequired(Contact {
        -1,
        ui->lineName->text(),
        ui->linePhoneNumber->text(),
        ui->lineEmail->text()
    });
}

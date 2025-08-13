#include "homeform.h"
#include "ui_homeform.h"

HomeForm::HomeForm(AppModel *model, QWidget *parent, HomeMenuOptions option)
    : QWidget(parent)
    , ui(new Ui::HomeForm)
    , model(model)
    , contactsListForm(nullptr)
    , newContactForm(nullptr)
    , currentBtnNav(nullptr)
{
    ui->setupUi(this);
    setMenuOption(option);

    // connecting nav buttons
    connect(ui->btnNavContacts, &QPushButton::clicked, this, [&]{ setMenuOption(Contacts); });
    connect(ui->btnNavNew, &QPushButton::clicked, this, [&]{ setMenuOption(NewContact); });
}

HomeForm::~HomeForm()
{
    delete ui;
}

ContactsListForm* HomeForm::getContactsListForm() { return contactsListForm; }
NewContactForm* HomeForm::getNewContactForm() { return newContactForm; }

void HomeForm::setMenuOption(HomeMenuOptions option)
{
    QWidget
        *widNew,
        *widOld = ui->widContent;

    QPushButton *btnNav;

    switch(option)
    {
    case Contacts:
        widNew = contactsListForm = new ContactsListForm(model->getContactsListModel(), this);
        btnNav = ui->btnNavContacts;

        connect(contactsListForm, &ContactsListForm::newContactRequired, this, [&]{ setMenuOption(NewContact); });

        break;

    case NewContact:
        widNew = newContactForm = new NewContactForm(this);
        btnNav = ui->btnNavNew;
        break;
    }

    if(currentBtnNav)
        currentBtnNav->setDisabled(false);

    currentBtnNav = btnNav;
    ui->widContent = widNew;

    btnNav->setDisabled(true);
    ui->layout->replaceWidget(widOld, widNew);
    widOld->deleteLater();
}

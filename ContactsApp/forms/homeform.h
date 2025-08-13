#ifndef HOMEFORM_H
#define HOMEFORM_H

#include "../models/consts.h"
#include "../models/appmodel.h"
#include "contactslistform.h"
#include "newcontactform.h"

#include <QWidget>
#include <QPushButton>

namespace Ui {
class HomeForm;
}

class HomeForm : public QWidget
{
    Q_OBJECT

public:
    explicit HomeForm(AppModel *model, QWidget *parent = nullptr, HomeMenuOptions option = Contacts);
    ~HomeForm();

    ContactsListForm* getContactsListForm();
    NewContactForm* getNewContactForm();

    void setMenuOption(HomeMenuOptions option);

private:
    Ui::HomeForm *ui;
    AppModel *model;
    ContactsListForm *contactsListForm;
    NewContactForm *newContactForm;
    QPushButton *currentBtnNav;
};

#endif // HOMEFORM_H

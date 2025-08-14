#ifndef APPVIEW_H
#define APPVIEW_H

#include "../models/appmodel.h"
#include "forms/contactmanagementform.h"
#include "forms/contactsform.h"
#include "forms/loadingform.h"

#include <QObject>
#include <QMainWindow>

class AppView : public QObject
{
    Q_OBJECT
public:
    explicit AppView(AppModel *model, QObject *parent = nullptr);

    enum Forms {
        ContactManagement,
        Contacts,
        Loading,
    };

    void setCurrentForm(Forms op);
    void initialize();

    ContactManagementForm* getContactManagementForm();
    ContactsForm* getContactsForm();
    LoadingForm* getLoadingForm();

private:
    QMainWindow *window;
    AppModel *model;
    ContactManagementForm *contactManagementForm;
    ContactsForm *contactsForm;
    LoadingForm *loadingForm;

signals:
    void formSet(Forms form);
    void contactManagementFormSet(ContactManagementForm *form);
    void contactsFormSet(ContactsForm *form);
    void loadingFormSet(LoadingForm *form);

};

#endif // APPVIEW_H

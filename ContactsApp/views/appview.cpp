#include "appview.h"

AppView::AppView(AppModel *model, QObject *parent)
    : QObject{parent}
    , window(new QMainWindow)
    , model(model)
    , contactManagementForm(nullptr)
    , contactsForm(nullptr)
    , loadingForm(nullptr)
{
    window->setMinimumSize(480, 560);
}

void AppView::setCurrentForm(Forms op)
{
    QWidget *wid;

    switch (op) {
    case ContactManagement:
        wid = contactManagementForm = new ContactManagementForm;
        break;

    case Contacts:
        wid = contactsForm = new ContactsForm(model);
        break;

    case Loading:
        wid = loadingForm = new LoadingForm;
        break;
    }

    window->setCentralWidget(wid);

    // dispatching events
    emit formSet(op);

    switch (op) {
    case ContactManagement:
        emit contactManagementFormSet(contactManagementForm);
        break;

    case Contacts:
        emit contactsFormSet(contactsForm);
        break;

    case Loading:
        emit loadingFormSet(loadingForm);
        break;
    }
}

void AppView::initialize()
{
    setCurrentForm(Loading);
    window->show();
}

ContactManagementForm* AppView::getContactManagementForm() { return contactManagementForm; }

ContactsForm* AppView::getContactsForm() { return contactsForm; }

LoadingForm* AppView::getLoadingForm() { return loadingForm; }

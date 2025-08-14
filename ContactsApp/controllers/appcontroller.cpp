#include "appcontroller.h"

AppController::AppController(AppModel *model, AppView *view, QObject *parent)
    : QObject{parent}
    , model(model)
    , view(view)
    , managementController(new ContactManagementController(model, view, this))
    , contactsController(new ContactsController(model, view, this))
{
    connect(this, SIGNAL(initializationFinished()), this, SLOT(on_initializationFinished()));
}

void AppController::initialize()
{
    view->initialize();
    model->initialize()
        .then([&] {
            emit initializationFinished();
        });
}

void AppController::on_initializationFinished()
{
    view->setCurrentForm(AppView::Forms::Contacts);
}

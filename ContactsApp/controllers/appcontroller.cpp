#include "appcontroller.h"
#include "../models/consts.h"

AppController::AppController(AppModel *model, AppView *view, QObject *parent)
    : QObject{parent}
    , model(model)
    , view(view)
{}

void AppController::initialize() {
    view->initialize();
    model->initialize()
        .then([&](bool success) {
            qDebug() << "success" << success;

            if(!success)
                return;

            auto contactsModel = this->view->getHomeForm()->getContactsListForm()->getModel();
            contactsModel->setContacts(ContactsList {
                { 0, "Iago Carvalho", "981409613", "iago@email.com" },
                { 1, "José Carvalho", "123456789", "jose@email.com" },
            });
        });
}

#include "contactmanagementcontroller.h"

#include <QDebug>

ContactManagementController::ContactManagementController(AppModel *model, AppView *view, QObject *parent)
    : QObject{parent}
    , model(model)
    , view(view)
    , form(nullptr)
{
    connect(view, SIGNAL(contactManagementFormSet(ContactManagementForm*)), this, SLOT(setForm(ContactManagementForm*)));
}

void ContactManagementController::setForm(ContactManagementForm *form)
{
    qDebug() << "ContactManagementController form set";
    this->form = form;

    if(!form)
        return;

    // connecting events
    connect(form, &ContactManagementForm::backRequired, this, &ContactManagementController::on_form_backRequired);
    connect(form, &ContactManagementForm::saveRequired, this, &ContactManagementController::on_form_saveRequired);
}

void ContactManagementController::on_form_saveRequired(const Contact& c) {
    if(c.id == -1)
        model->addContact(c);
    else
        model->updateContact(c);

    view->setCurrentForm(AppView::Forms::Contacts);
}

void ContactManagementController::on_form_backRequired() {
    view->setCurrentForm(AppView::Forms::Contacts);
}

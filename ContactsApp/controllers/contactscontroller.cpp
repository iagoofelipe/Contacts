#include "contactscontroller.h"

#include <QDebug>

ContactsController::ContactsController(AppModel *model, AppView *view, QObject *parent)
    : QObject{parent}
    , model(model)
    , view(view)
    , form(nullptr)
{
    connect(view, SIGNAL(contactsFormSet(ContactsForm*)), this, SLOT(setForm(ContactsForm*)));
}

void ContactsController::setForm(ContactsForm *form)
{
    qDebug() << "ContactsController form set";
    this->form = form;

    if(!form)
        return;

    // connecting events
    connect(form, &ContactsForm::newRequired, this, &ContactsController::on_form_newRequired);
    connect(form, &ContactsForm::editRequired, this, &ContactsController::on_form_editRequired);
    connect(form, &ContactsForm::deleteRequired, this, &ContactsController::on_form_deleteRequired);
    connect(form, &ContactsForm::detailsRequired, this, &ContactsController::on_form_detailsRequired);
}

void ContactsController::on_form_newRequired() {
    view->setCurrentForm(AppView::Forms::ContactManagement);
    view->getContactManagementForm()->setMode(ContactManagementForm::Modes::New);
}

void ContactsController::on_form_editRequired(int id) {
    view->setCurrentForm(AppView::Forms::ContactManagement);
    view->getContactManagementForm()->setMode(ContactManagementForm::Modes::Edit, model->getContactById(id));
}

void ContactsController::on_form_detailsRequired(int id) {
    view->setCurrentForm(AppView::Forms::ContactManagement);
    view->getContactManagementForm()->setMode(ContactManagementForm::Modes::Display, model->getContactById(id));
}

void ContactsController::on_form_deleteRequired(const QList<int>& ids) {
    model->removeContacts(ids);
}

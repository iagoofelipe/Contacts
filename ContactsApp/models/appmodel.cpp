#include "appmodel.h"

#include <QtConcurrent>

AppModel::AppModel(QObject *parent)
    : QObject{parent}
    , contactsListModel(new ContactsListModel(this))
{}

ContactsListModel* AppModel::getContactsListModel() { return contactsListModel; }

QFuture<bool> AppModel::initialize() {
    return QtConcurrent::run([&]{ return _initialize(); } );
}

bool AppModel::_initialize() {


    return true;
}

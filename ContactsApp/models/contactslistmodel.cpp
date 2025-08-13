#include "contactslistmodel.h"
#include <algorithm>
#include <QDebug>

ContactsListModel::ContactsListModel(QObject *parent)
    : QObject{parent}
    , hasFilter(false)
{}

void ContactsListModel::setContacts(const ContactsList values) {
    contacts = values;
    hasFilter = false;

    // sorting
    std::sort(contacts.begin(), contacts.end(), [](const Contact &a, const Contact &b) {
        return a.name < b.name;
    });

    emit contactsChanged(&contacts);
}

ContactsList* ContactsListModel::getContacts()
{
    return hasFilter? &filtered : &contacts;
}

void ContactsListModel::setFilter(const QString name)
{
    qDebug() << "ContactsListModel::setFilter name" << name;
    filtered = contacts;
    hasFilter = true;

    filtered.removeIf([&](const Contact &contact) {
        return !contact.name.contains(name, Qt::CaseInsensitive);
    });

    qDebug() << "ContactsListModel::setFilter" << filtered.count() << "match(es)";
    emit contactsChanged(&filtered);
}

void ContactsListModel::clearFilter() {
    if(!hasFilter)
        return;

    hasFilter = false;
    emit contactsChanged(&contacts);
}

QList<QChar> ContactsListModel::getLetters()
{
    QList<QChar> values;
    const ContactsList *_contacts = getContacts();

    for(const auto& contact : *_contacts) {
        QChar letter = contact.name[0];

        if(!values.contains(letter))
            values.append(letter);
    }

    return values;
}

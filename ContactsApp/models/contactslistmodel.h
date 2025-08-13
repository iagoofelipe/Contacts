#ifndef CONTACTSLISTMODEL_H
#define CONTACTSLISTMODEL_H

#include "consts.h"

#include <QObject>
#include <QList>

class ContactsListModel : public QObject
{
    Q_OBJECT
public:
    explicit ContactsListModel(QObject *parent = nullptr);

    void setContacts(const ContactsList values);
    ContactsList* getContacts();
    void setFilter(const QString name);
    void clearFilter();
    QList<QChar> getLetters();

signals:
    void contactsChanged(ContactsList *values);

private:
    ContactsList contacts;
    ContactsList filtered;
    bool hasFilter;
};

#endif // CONTACTSLISTMODEL_H

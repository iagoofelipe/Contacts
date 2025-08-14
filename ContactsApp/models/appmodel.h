#ifndef APPMODEL_H
#define APPMODEL_H

#include "consts.h"

#include <QObject>
#include <QFuture>

class AppModel : public QObject
{
    Q_OBJECT
public:
    explicit AppModel(QObject *parent = nullptr);

    QFuture<void> initialize();
    void close();

    const ContactMap& getContacts();
    const Contact& getContactById(int id);
    void getFiltered(const QString& name, ContactMap& out);
    void getLetters(const ContactMap& values, QMap<QChar, QList<int>>& out);

    void addContact(const Contact& contact);
    void updateContact(const Contact& contact);
    void removeContact(int id);
    void removeContacts(const QList<int>& ids);

private:
    ContactMap contacts;

    void _initialize();
    void readContactsFromDll(bool dispatch = false);

signals:
    void contactsChanged(const ContactMap& contacts);
};

#endif // APPMODEL_H

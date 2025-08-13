#ifndef CONSTS_H
#define CONSTS_H

#include <QString>
#include <QList>

enum HomeMenuOptions {
    Contacts, NewContact
};

struct Contact {
    int id;
    QString name;
    QString number;
    QString email;
};

typedef QList<Contact> ContactsList;

#endif // CONSTS_H

#ifndef CONSTS_H
#define CONSTS_H

#include <QString>
#include <QList>
#include <QMap>

struct Contact {
    int id;
    QString name;
    QString phone;
    QString email;
};

// typedef QList<Contact> ContactList;

typedef QMap<int, Contact> ContactMap;

#endif // CONSTS_H

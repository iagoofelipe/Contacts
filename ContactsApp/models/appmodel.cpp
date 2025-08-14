#include "appmodel.h"

#include <Contacts.h>
#include <QtConcurrentRun>
#include <QThread>
#include <QDebug>
#include <QDir>

AppModel::AppModel(QObject *parent)
    : QObject{parent}
{}

void AppModel::close()
{
    qDebug() << "cleaning DLL properties";
    contacts::clear();
}

QFuture<void> AppModel::initialize()
{
    return QtConcurrent::run([&]{ return _initialize(); });
}

const ContactMap& AppModel::getContacts() { return contacts; }

const Contact& AppModel::getContactById(int id) { return contacts[id]; }

void AppModel::getFiltered(const QString& name, ContactMap& out)
{
    out = contacts;

    if(name.isEmpty())
        return;

    for(const auto& c : std::as_const(contacts)) {
        if(!c.name.contains(name, Qt::CaseInsensitive))
            out.remove(c.id);
    }
}

void AppModel::getLetters(const ContactMap& values, QMap<QChar, QList<int>>& out)
{
    if(!out.empty())
        out.clear();

    for(const auto& c : values) {
        QChar letter = c.name[0];

        if(!out.count(letter))
            out[letter] = QList<int>();

        out[letter].push_back(c.id);
    }
}

void AppModel::addContact(const Contact& c)
{
    QByteArray
        bname = c.name.toUtf8(),
        bphone = c.phone.toUtf8(),
        bemail = c.email.toUtf8();

    const char
        *name = bname.data(),
        *phone = bphone.data(),
        *email = bemail.data();

    contacts::addContactByFields(name, phone, email);
    readContactsFromDll(true);
}

void AppModel::updateContact(const Contact& c)
{
    QByteArray
        bname = c.name.toUtf8(),
        bphone = c.phone.toUtf8(),
        bemail = c.email.toUtf8();

    const char
        *name = bname.data(),
        *phone = bphone.data(),
        *email = bemail.data();

    if(!contacts::updateContactByFields(c.id, name, phone, email))
        return;

    contacts[c.id] = c;
    emit contactsChanged(contacts);
}

void AppModel::removeContact(int id)
{
    contacts::removeContact(id);
    contacts.remove(id);
    emit contactsChanged(contacts);
}

void AppModel::removeContacts(const QList<int>& ids)
{
    size_t size = ids.size();
    int *array = new int[size];

    for(int i=0; i < size; i++) {
        int id = ids[i];
        array[i] = id;

        contacts.remove(id);
    }

    contacts::removeContacts(array, size);
    delete[] array;

    emit contactsChanged(contacts);
}

void AppModel::_initialize()
{
    contacts::initialize();
    readContactsFromDll();

    QThread::sleep(1);
}

void AppModel::readContactsFromDll(bool dispatch)
{
    size_t size;
    contacts::Contact** array = contacts::getContacts(&size);

    contacts.clear();

    qDebug() << size << "contacts found on the base, dir" << QDir::currentPath() << "file" << contacts::FILENAME;

    for(int i=0; i < size; i++) {
        contacts::Contact* c = array[i];
        contacts[c->id] = { c->id, c->name, c->phone, c->email };
    }

    if(dispatch)
        emit contactsChanged(contacts);
}

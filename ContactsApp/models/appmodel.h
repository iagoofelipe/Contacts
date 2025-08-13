#ifndef APPMODEL_H
#define APPMODEL_H

#include "contactslistmodel.h"

#include <QObject>
#include <QFuture>

class AppModel : public QObject
{
    Q_OBJECT
public:
    explicit AppModel(QObject *parent = nullptr);

    ContactsListModel* getContactsListModel();
    QFuture<bool> initialize();

private:
    ContactsListModel *contactsListModel;

    bool _initialize();

};

#endif // APPMODEL_H

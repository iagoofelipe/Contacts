#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "../models/appmodel.h"
#include "../views/appview.h"
#include "contactmanagementcontroller.h"
#include "contactscontroller.h"

#include <QObject>

class AppController : public QObject
{
    Q_OBJECT
public:
    explicit AppController(AppModel *model, AppView *view, QObject *parent = nullptr);

    void initialize();

private:
    AppModel *model;
    AppView *view;
    ContactManagementController *managementController;
    ContactsController *contactsController;

private slots:
    void on_initializationFinished();

signals:
    void initializationFinished();
};

#endif // APPCONTROLLER_H

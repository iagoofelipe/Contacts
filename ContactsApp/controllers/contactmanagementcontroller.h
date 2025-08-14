#ifndef CONTACTMANAGEMENTCONTROLLER_H
#define CONTACTMANAGEMENTCONTROLLER_H

#include "../models/appmodel.h"
#include "../views/appview.h"

#include <QObject>

class ContactManagementController : public QObject
{
    Q_OBJECT
public:
    explicit ContactManagementController(AppModel *model, AppView *view, QObject *parent = nullptr);

public slots:
    void setForm(ContactManagementForm *form);

private:
    AppModel *model;
    AppView *view;
    ContactManagementForm *form;

    void on_form_saveRequired(const Contact& c);
    void on_form_backRequired();

signals:
};

#endif // CONTACTMANAGEMENTCONTROLLER_H

#ifndef CONTACTSCONTROLLER_H
#define CONTACTSCONTROLLER_H

#include "../models/appmodel.h"
#include "../views/appview.h"

#include <QObject>

class ContactsController : public QObject
{
    Q_OBJECT
public:
    explicit ContactsController(AppModel *model, AppView *view, QObject *parent = nullptr);

public slots:
    void setForm(ContactsForm *form);

private:
    AppModel *model;
    AppView *view;
    ContactsForm *form;

    void on_form_newRequired();
    void on_form_editRequired(int id);
    void on_form_detailsRequired(int id);
    void on_form_deleteRequired(const QList<int>& ids);

signals:
};

#endif // CONTACTSCONTROLLER_H

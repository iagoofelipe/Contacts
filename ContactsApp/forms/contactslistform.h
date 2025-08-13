#ifndef CONTACTSLISTFORM_H
#define CONTACTSLISTFORM_H

#include "../models/contactslistmodel.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QSpacerItem>

namespace Ui {
class ContactsListForm;
}

class ContactsListForm : public QWidget
{
    Q_OBJECT

public:
    explicit ContactsListForm(ContactsListModel *model = nullptr, QWidget *parent = nullptr);
    ~ContactsListForm();

    ContactsListModel *getModel();
    void setContacts(ContactsList *values);

signals:
    void newContactRequired();

private:
    Ui::ContactsListForm *ui;
    ContactsListModel *model;
    QVBoxLayout *layout;
    QSpacerItem *spacer;
    QList<QWidget*> widgets;

    void on_btnSearch_clicked();
};

#endif // CONTACTSLISTFORM_H

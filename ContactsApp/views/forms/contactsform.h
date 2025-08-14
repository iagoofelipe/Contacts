#ifndef CONTACTSFORM_H
#define CONTACTSFORM_H

#include "../../models/appmodel.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QCheckBox>
#include <unordered_set>

namespace Ui {
class ContactsForm;
}

class ContactsForm : public QWidget
{
    Q_OBJECT

public:
    explicit ContactsForm(AppModel *model, QWidget *parent = nullptr);
    ~ContactsForm();

    void setContacts(const ContactMap& contacts);
    void clearSelections(bool uncheck = true);

signals:
    void newRequired();
    void editRequired(int id);
    void detailsRequired(int id);
    void deleteRequired(const QList<int>& ids);

private:
    Ui::ContactsForm *ui;
    AppModel *model;
    QVBoxLayout *layout;
    QSpacerItem *spacer;
    QList<QWidget*> widgets;
    std::unordered_set<int> selectedIds;
    std::unordered_set<QCheckBox*> selectedWidgets;

    void on_btnSearch_clicked();
    void on_btnEdit_clicked();
    void on_btnDelete_clicked();
    void on_checkBox_checkStateChanged(Qt::CheckState state);
    void on_btnDetails_clicked();
};

#endif // CONTACTSFORM_H

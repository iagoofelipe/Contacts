#ifndef CONTACTMANAGEMENTFORM_H
#define CONTACTMANAGEMENTFORM_H

#include "../../models/consts.h"

#include <QWidget>

namespace Ui {
class ContactManagementForm;
}

class ContactManagementForm : public QWidget
{
    Q_OBJECT

public:
    explicit ContactManagementForm(QWidget *parent = nullptr);
    ~ContactManagementForm();

    enum Modes {
        New, Edit, Display
    };

    static QString TitleModeNew;
    static QString TitleModeEdit;
    static QString TitleModeDisplay;

    void setMode(Modes mode);
    void setMode(Modes mode, const Contact& c);
    void clear();

signals:
    void saveRequired(const Contact& c);
    void backRequired();

private:
    Ui::ContactManagementForm *ui;
    Modes currentMode;
    int contactId;

    void on_btnSave_clicked();
};

#endif // CONTACTMANAGEMENTFORM_H

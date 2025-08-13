#ifndef NEWCONTACTFORM_H
#define NEWCONTACTFORM_H

#include "../models/consts.h"

#include <QWidget>

namespace Ui {
class NewContactForm;
}

class NewContactForm : public QWidget
{
    Q_OBJECT

public:
    explicit NewContactForm(QWidget *parent = nullptr);
    ~NewContactForm();

signals:
    void saveRequired(const Contact data);

private:
    Ui::NewContactForm *ui;

    void on_btnClear_clicked();
    void on_btnSave_clicked();
};

#endif // NEWCONTACTFORM_H

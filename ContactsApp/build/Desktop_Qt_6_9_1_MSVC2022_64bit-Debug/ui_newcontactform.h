/********************************************************************************
** Form generated from reading UI file 'newcontactform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCONTACTFORM_H
#define UI_NEWCONTACTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewContactForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineName;
    QLabel *label_2;
    QLineEdit *linePhoneNumber;
    QLabel *label_3;
    QLineEdit *lineEmail;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClear;
    QPushButton *btnSave;

    void setupUi(QWidget *NewContactForm)
    {
        if (NewContactForm->objectName().isEmpty())
            NewContactForm->setObjectName("NewContactForm");
        NewContactForm->resize(813, 605);
        QFont font;
        font.setPointSize(12);
        NewContactForm->setFont(font);
        NewContactForm->setStyleSheet(QString::fromUtf8("QLineEdit { padding: 10; }"));
        verticalLayout = new QVBoxLayout(NewContactForm);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(NewContactForm);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label);

        lineName = new QLineEdit(NewContactForm);
        lineName->setObjectName("lineName");

        verticalLayout->addWidget(lineName);

        label_2 = new QLabel(NewContactForm);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        linePhoneNumber = new QLineEdit(NewContactForm);
        linePhoneNumber->setObjectName("linePhoneNumber");

        verticalLayout->addWidget(linePhoneNumber);

        label_3 = new QLabel(NewContactForm);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        lineEmail = new QLineEdit(NewContactForm);
        lineEmail->setObjectName("lineEmail");

        verticalLayout->addWidget(lineEmail);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(NewContactForm);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnClear = new QPushButton(widget);
        btnClear->setObjectName("btnClear");

        horizontalLayout->addWidget(btnClear);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName("btnSave");

        horizontalLayout->addWidget(btnSave);


        verticalLayout->addWidget(widget);


        retranslateUi(NewContactForm);

        QMetaObject::connectSlotsByName(NewContactForm);
    } // setupUi

    void retranslateUi(QWidget *NewContactForm)
    {
        NewContactForm->setWindowTitle(QCoreApplication::translate("NewContactForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("NewContactForm", "Name*", nullptr));
        label_2->setText(QCoreApplication::translate("NewContactForm", "Phone Number", nullptr));
        label_3->setText(QCoreApplication::translate("NewContactForm", "E-mail", nullptr));
        btnClear->setText(QCoreApplication::translate("NewContactForm", "clear", nullptr));
        btnSave->setText(QCoreApplication::translate("NewContactForm", "save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewContactForm: public Ui_NewContactForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCONTACTFORM_H

/********************************************************************************
** Form generated from reading UI file 'contactslistform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTSLISTFORM_H
#define UI_CONTACTSLISTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactsListForm
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineSearch;
    QPushButton *btnSearch;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnNew;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QScrollArea *scrollArea;
    QWidget *widList;

    void setupUi(QWidget *ContactsListForm)
    {
        if (ContactsListForm->objectName().isEmpty())
            ContactsListForm->setObjectName("ContactsListForm");
        ContactsListForm->resize(950, 608);
        QFont font;
        font.setPointSize(12);
        ContactsListForm->setFont(font);
        ContactsListForm->setStyleSheet(QString::fromUtf8("QPushButton { padding: 5; }"));
        verticalLayout = new QVBoxLayout(ContactsListForm);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(ContactsListForm);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineSearch = new QLineEdit(widget_2);
        lineSearch->setObjectName("lineSearch");
        lineSearch->setStyleSheet(QString::fromUtf8("padding: 5;"));

        horizontalLayout_2->addWidget(lineSearch);

        btnSearch = new QPushButton(widget_2);
        btnSearch->setObjectName("btnSearch");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        btnSearch->setIcon(icon);
        btnSearch->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(btnSearch);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(ContactsListForm);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnNew = new QPushButton(widget);
        btnNew->setObjectName("btnNew");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        btnNew->setIcon(icon1);
        btnNew->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btnNew);

        btnEdit = new QPushButton(widget);
        btnEdit->setObjectName("btnEdit");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        btnEdit->setIcon(icon2);
        btnEdit->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(widget);
        btnDelete->setObjectName("btnDelete");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        btnDelete->setIcon(icon3);
        btnDelete->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btnDelete);


        verticalLayout->addWidget(widget);

        scrollArea = new QScrollArea(ContactsListForm);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        widList = new QWidget();
        widList->setObjectName("widList");
        widList->setGeometry(QRect(0, 0, 948, 530));
        scrollArea->setWidget(widList);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(ContactsListForm);

        QMetaObject::connectSlotsByName(ContactsListForm);
    } // setupUi

    void retranslateUi(QWidget *ContactsListForm)
    {
        ContactsListForm->setWindowTitle(QCoreApplication::translate("ContactsListForm", "Form", nullptr));
        lineSearch->setPlaceholderText(QCoreApplication::translate("ContactsListForm", "Type a name to search...", nullptr));
        label->setText(QCoreApplication::translate("ContactsListForm", "Contacts List", nullptr));
#if QT_CONFIG(tooltip)
        btnNew->setToolTip(QCoreApplication::translate("ContactsListForm", "add new contact", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNew->setText(QString());
#if QT_CONFIG(tooltip)
        btnEdit->setToolTip(QCoreApplication::translate("ContactsListForm", "edit selected contact", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnDelete->setToolTip(QCoreApplication::translate("ContactsListForm", "delete selected contacts", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class ContactsListForm: public Ui_ContactsListForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTSLISTFORM_H

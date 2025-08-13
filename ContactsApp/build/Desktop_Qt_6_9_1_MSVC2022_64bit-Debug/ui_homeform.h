/********************************************************************************
** Form generated from reading UI file 'homeform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEFORM_H
#define UI_HOMEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeForm
{
public:
    QHBoxLayout *layout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QPushButton *btnNavContacts;
    QPushButton *btnNavNew;
    QSpacerItem *verticalSpacer;
    QWidget *widContent;

    void setupUi(QWidget *HomeForm)
    {
        if (HomeForm->objectName().isEmpty())
            HomeForm->setObjectName("HomeForm");
        HomeForm->resize(1000, 600);
        HomeForm->setMinimumSize(QSize(1000, 600));
        layout = new QHBoxLayout(HomeForm);
        layout->setObjectName("layout");
        frame = new QFrame(HomeForm);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("QPushButton { padding: 10; background-color: transparent; }"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        btnNavContacts = new QPushButton(frame);
        btnNavContacts->setObjectName("btnNavContacts");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        btnNavContacts->setIcon(icon);
        btnNavContacts->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(btnNavContacts);

        btnNavNew = new QPushButton(frame);
        btnNavNew->setObjectName("btnNavNew");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        btnNavNew->setIcon(icon1);
        btnNavNew->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(btnNavNew);

        verticalSpacer = new QSpacerItem(20, 453, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        layout->addWidget(frame);

        widContent = new QWidget(HomeForm);
        widContent->setObjectName("widContent");

        layout->addWidget(widContent);


        retranslateUi(HomeForm);

        QMetaObject::connectSlotsByName(HomeForm);
    } // setupUi

    void retranslateUi(QWidget *HomeForm)
    {
        HomeForm->setWindowTitle(QCoreApplication::translate("HomeForm", "Form", nullptr));
        btnNavContacts->setText(QCoreApplication::translate("HomeForm", "Contacts", nullptr));
        btnNavNew->setText(QCoreApplication::translate("HomeForm", "New Contact", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeForm: public Ui_HomeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEFORM_H

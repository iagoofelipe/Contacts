QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    app.cpp \
    controllers/appcontroller.cpp \
    forms/contactslistform.cpp \
    forms/homeform.cpp \
    forms/newcontactform.cpp \
    main.cpp \
    models/appmodel.cpp \
    models/contactslistmodel.cpp \
    views/appview.cpp

HEADERS += \
    app.h \
    controllers/appcontroller.h \
    forms/contactslistform.h \
    forms/homeform.h \
    forms/newcontactform.h \
    models/appmodel.h \
    models/consts.h \
    models/contactslistmodel.h \
    views/appview.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    forms/contactslistform.ui \
    forms/homeform.ui \
    forms/newcontactform.ui

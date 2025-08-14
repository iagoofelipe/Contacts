QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets concurrent

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    application.cpp \
    controllers/appcontroller.cpp \
    controllers/contactmanagementcontroller.cpp \
    controllers/contactscontroller.cpp \
    main.cpp \
    models/appmodel.cpp \
    views/appview.cpp \
    views/forms/contactmanagementform.cpp \
    views/forms/contactsform.cpp \
    views/forms/loadingform.cpp

HEADERS += \
    application.h \
    controllers/appcontroller.h \
    controllers/contactmanagementcontroller.h \
    controllers/contactscontroller.h \
    models/appmodel.h \
    models/consts.h \
    views/appview.h \
    views/forms/contactmanagementform.h \
    views/forms/contactsform.h \
    views/forms/loadingform.h

FORMS += \
    views/forms/contactmanagementform.ui \
    views/forms/contactsform.ui \
    views/forms/loadingform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../x64/Release/ -lContactsDLL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../x64/Debug/ -lContactsDLL

INCLUDEPATH += $$PWD/../ContactsDLL
DEPENDPATH += $$PWD/../ContactsDLL

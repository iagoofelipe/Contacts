#ifndef APPLICATION_H
#define APPLICATION_H

#include "controllers/appcontroller.h"

#include <QApplication>

class Application : public QApplication
{
public:
    Application(int argc, char** argv);

    int exec();

private:
    AppModel *model;
    AppView *view;
    AppController *controller;
};

#endif // APPLICATION_H

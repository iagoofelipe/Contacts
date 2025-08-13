#ifndef APP_H
#define APP_H

#include "models/appmodel.h"
#include "views/appview.h"
#include "controllers/appcontroller.h"

#include <QApplication>

class App : public QApplication
{
public:
    explicit App(int argc, char *argv[]);

    int exec();

private:
    AppModel *model;
    AppView *view;
    AppController *controller;
};

#endif // APP_H

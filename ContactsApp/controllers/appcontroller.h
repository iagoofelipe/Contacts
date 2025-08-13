#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "../models/appmodel.h"
#include "../views/appview.h"

#include <QObject>

class AppController : public QObject
{
    Q_OBJECT
public:
    explicit AppController(AppModel *model, AppView *view, QObject *parent = nullptr);

    void initialize();

signals:

private:
    AppModel *model;
    AppView *view;

};

#endif // APPCONTROLLER_H

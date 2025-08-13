#ifndef APPVIEW_H
#define APPVIEW_H

#include "../models/appmodel.h"
#include "../forms/homeform.h"


#include <QObject>
#include <QMainWindow>

class AppView : public QObject
{
    Q_OBJECT
public:
    explicit AppView(AppModel *model, QObject *parent = nullptr);

    void initialize();
    HomeForm* getHomeForm();

signals:

private:
    AppModel *model;
    QMainWindow *window;
    HomeForm *homeForm;
};

#endif // APPVIEW_H

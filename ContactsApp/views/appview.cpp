#include "appview.h"

AppView::AppView(AppModel *model, QObject *parent)
    : QObject{parent}
    , model(model)
    , window(new QMainWindow)
{}

HomeForm* AppView::getHomeForm() { return homeForm; }

void AppView::initialize() {
    window->setCentralWidget(homeForm = new HomeForm(model));
    window->show();
}

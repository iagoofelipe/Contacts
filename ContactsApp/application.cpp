#include "application.h"

Application::Application(int argc, char** argv)
    : QApplication(argc, argv)
    , model(new AppModel)
    , view(new AppView(model))
    , controller(new AppController(model, view))
{
    connect(this, &QApplication::aboutToQuit, [&] { model->close(); });
}

int Application::exec()
{
    controller->initialize();
    return QApplication::exec();
}

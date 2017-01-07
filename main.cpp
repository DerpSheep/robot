#include <QApplication>
#include <QDebug>
#include "window.h"
#include "main.h"
#include "robotview.h"
#include "qt3dwindow.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);

    qDebug() << "from main";

    //Show the GUI
    Window window;
    window.show();

    //Initialize app
    return app.exec();

}

#include "mainwindow.h"

#include <QApplication>
#include <coreitem.h>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <shortcutfilter.h>
#include <qdesktopwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QDesktopWidget *desktop = QApplication::desktop();
    w.move((desktop->width() - w.width())/ 2, (desktop->height() - w.height()) /2);
    return a.exec();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <coreitem.h>
#include <QHBoxLayout>
#include <QProcess>
#include <QKeyEvent>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radioPerformance_toggled(bool checked);

    void on_radioBalance_toggled(bool checked);

    void on_radioPowersave_toggled(bool checked);


private:
    Ui::MainWindow *ui;
    const QString cmdMaxFreq="sudo -S cpupower -c all frequency-set -u 1000000GHz";
    const QString cmdLowFreq="sudo -S cpupower -c all frequency-set -u 1.1GHz";
    const QString cmdPerformance ="sudo -S cpupower -c all frequency-set -g performance";
    const QString cmdBalance ="sudo -S cpupower -c all frequency-set -g powersave";
    const QString cmdPowersave ="sudo -S cpupower -c all frequency-set -g powersave";
    const QString cmdPolicyInfo="cpupower frequency-info -p";
    const QString FLAG_POWERSAVE="powersave";
    const QString FLAG_PERFORMANCE="performance";
    const QString LIMT_POWERSAVE="4.70 GHz";
    enum Model{BALANCE=0,POWERSAVE=1,PERFORMANCE=2,UNKNOW=-1};
    QTimer *delayHiden;
    Model model=UNKNOW;
    void currentModel();


};
#endif // MAINWINDOW_H

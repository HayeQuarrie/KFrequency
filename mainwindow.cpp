#include "mainwindow.h"
#include "qxtglobalshortcut.h"

#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    delayHiden=new QTimer(this);
    delayHiden->setSingleShot(true);
    ui->setupUi(this);
    //connect(delayHiden, &QTimer::timeout, this, [=](){this->hide();});
    QxtGlobalShortcut *shortcut = new QxtGlobalShortcut(this);
    shortcut->setShortcut(QKeySequence("Ctrl+Shift+Alt+m"));
    connect(shortcut, &QxtGlobalShortcut::activated,[=]()
    {
        //this->show();
        qDebug()<<  model;
        switch((model+1)%3){
        case BALANCE:ui->radioBalance->setChecked(true);break;
        case POWERSAVE:ui->radioPowersave->setChecked(true);break;
        case PERFORMANCE:ui->radioPerformance->setChecked(true);break;
        default:break;
        }
        //delayHiden->start(3000);
    });
   currentModel();

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::currentModel(){
    QProcess *runShellProcess =new QProcess(this);
    connect(runShellProcess,&QProcess::readyRead,[=](){
        QString shellRessult=runShellProcess->readAll();
        qDebug()<<shellRessult;
        if(-1!=shellRessult.indexOf(FLAG_PERFORMANCE)){
            ui->radioPerformance->setChecked(true);
            model= PERFORMANCE;

        }else if(-1!=shellRessult.indexOf(FLAG_POWERSAVE)){
            if(shellRessult.lastIndexOf(LIMT_POWERSAVE)<shellRessult.lastIndexOf("and")){

                ui->radioPowersave->setChecked(true);
                model= POWERSAVE;

            }else{
                model= BALANCE;
                ui->radioBalance->setChecked(true);

            }
        }
    });
    runShellProcess->start(cmdPolicyInfo);
}



void MainWindow::on_radioPerformance_toggled(bool checked)
{

    if(checked){
        int result=QProcess::execute(cmdPerformance);
        if(0==result){
            result=QProcess::execute(cmdMaxFreq);
            model=PERFORMANCE;
        }
    }
}

void MainWindow::on_radioBalance_toggled(bool checked)
{
    if(checked){
        int result=QProcess::execute(cmdBalance);
        if(0==result){
            result=QProcess::execute(cmdMaxFreq);
            model=BALANCE;
        }
    }
}

void MainWindow::on_radioPowersave_toggled(bool checked)
{
    if(checked){
        int result=QProcess::execute(cmdPowersave);
        if(0==result){
            result=QProcess::execute(cmdLowFreq);
            model=POWERSAVE;
        }
    }
}

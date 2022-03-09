#include "nodewindow.h"
#include "ui_nodewindow.h"
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

NodeWindow::NodeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NodeWindow)
{
    ui->setupUi(this);
    //treewidget
    AddRoot("Node 1");
    AddRoot("Node 2");
    AddRoot("Node 3");
    AddRoot("Node 4");
    //Node Status Section
    connect(ui->updatestatus, SIGNAL(clicked(bool)), this, SLOT(UpdateNodes()));
    connect(ui->ExitButton, SIGNAL(clicked(bool)), this, SLOT(QUIT()));
}

NodeWindow::~NodeWindow()
{
    delete ui;
}

void NodeWindow::File()
{
    QFile file("");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in(&file);
    ui->textEdit_node1->setText(in.readAll());
}

void NodeWindow::QUIT()
{
    QCoreApplication::quit();
}

void NodeWindow::AddRoot(QString name)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0, name);
    ui->treeWidget->addTopLevelItem(item);

    AddChild(item,"info");
}
void NodeWindow::AddChild(QTreeWidgetItem *parent, QString name)
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,name);
    parent->addChild(item);
}
void NodeWindow::UpdateNodes()
{
    //Depends on what is recieved for ONLINE/OFFLINE
    int status1 = 0;
    int status2 = 0;
    int status3 = 0;
    int status4 = 0;
    //need to check signal here as to what is recieved.
    //Node 1 Status checker
    if(status1 == 0)
    {
        ui->Node1Status->setText("OFFLINE");
    }
    else
    {
        ui->Node1Status->setText("ONLINE");
    }

    if(status2 == 0)
    {
        ui->Node2Status->setText("OFFLINE");
    }
    else
    {
        ui->Node2Status->setText("ONLINE");
    }

    if(status3 == 0)
    {
        ui->Node3Status->setText("OFFLINE");
    }
    else
    {
        ui->Node3Status->setText("ONLINE");
    }

    if(status4 == 0)
    {
        ui->Node4Status->setText("OFFLINE");
    }
    else
    {
        ui->Node4Status->setText("ONLINE");
    }
}

#ifndef NODEWINDOW_H
#define NODEWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class NodeWindow; }
QT_END_NAMESPACE

class NodeWindow : public QMainWindow
{
    Q_OBJECT


public:
    NodeWindow(QWidget *parent = nullptr);
    ~NodeWindow();

private:
    Ui::NodeWindow *ui;

private slots:
    void UpdateNodes();
    void QUIT();
    void AddRoot(QString name);
    void AddChild(QTreeWidgetItem *parent, QString name);
    void File();
};
#endif // NODEWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void run();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Graph graph;

private slots:
    void showShortestPath();
    void showMiniTree();
    void showBetweenness();
    void showCloseness();

};

#endif // MAINWINDOW_H

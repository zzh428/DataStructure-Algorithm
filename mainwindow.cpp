#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QString>
#include <QInputDialog>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(showShortestPath()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(showMiniTree()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(showBetweenness()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(showCloseness()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showShortestPath()
{
    int begin, end;
    begin = QInputDialog::getInt(NULL,"请输入起点","请输入起点:");
    end = QInputDialog::getInt(NULL,"请输入终点","请输入终点:");
    graph.shortestPath(begin,end);
    graph.showShortestPathGraph();
    QDesktopServices::openUrl(QUrl::fromLocalFile("graph.html"));
}

void MainWindow::showMiniTree()
{
    graph.showShortestTreeGraph();
    QDesktopServices::openUrl(QUrl::fromLocalFile("graph.html"));
}

void MainWindow::showBetweenness()
{
    graph.showBetweennessGraph();
    QDesktopServices::openUrl(QUrl::fromLocalFile("graph.html"));
}

void MainWindow::showCloseness()
{
    graph.showClosenessGraph();
    QDesktopServices::openUrl(QUrl::fromLocalFile("graph.html"));
}

void MainWindow::run()
{
    graph.floyd();
    graph.centrality();
    graph.prim();
    ofstream fout("out.csv", ios::out);
    graph.showCtrlty(fout);
    fout.close();
    fout.open("tree.txt",ios::out);
    graph.showShortestTree(fout);
}

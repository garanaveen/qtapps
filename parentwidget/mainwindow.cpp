#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mapwidget.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);

//   QObject::connect(this, &MainWindow::DummySignal, this, &MainWindow::DummySlot);
   MapWidgetWithControls* theWidget = new MapWidgetWithControls(this);
   connect(theWidget, SIGNAL(DummySignal()), theWidget, SLOT(DummySlot()));
   theWidget->EmitDummySignal();

   Q_UNUSED(theWidget)
}
MainWindow::~MainWindow()
{
   delete ui;
}

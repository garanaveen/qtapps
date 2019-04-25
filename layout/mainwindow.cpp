#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>

static int i = 1;
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   QWidget* myCentralWidget = new QWidget(this);
   myCentralWidget->setObjectName(QString::fromUtf8("myCentralWidget"));

   QWidget* myVerticalLayoutWidget = new QWidget(myCentralWidget);
   myVerticalLayoutWidget->setObjectName(QString::fromUtf8("myVerticalLayoutWidget"));

   QVBoxLayout* myVerticalLayout = new QVBoxLayout(myVerticalLayoutWidget);
   myVerticalLayout->setObjectName(QString::fromUtf8("myVerticalLayout"));

   for(int j = 0; j < 1; j++)
   {
      myVerticalLayout->addWidget(CreateRadioButtonItem());
      myVerticalLayout->addWidget(CreateRadioButtonItemSubText());
   }

   setCentralWidget(myCentralWidget);
}

MainWindow::~MainWindow()
{
   delete ui;
}

QRadioButton* MainWindow::CreateRadioButtonItem()
{
   QString rbText = QString("Item-%1").arg(i);
   QRadioButton* rb = new QRadioButton(rbText);
   return rb;
}

QLabel* MainWindow::CreateRadioButtonItemSubText()
{
   QString rbText = QString("ItemSubText-%1").arg(i);

   QLabel* l = new QLabel("SubText");
   i++;
   return l;
}

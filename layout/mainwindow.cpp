#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_radiobuttonitemwidget.h"
#include <QVBoxLayout>

static int i = 0;

void MainWindow::CreateLayoutItem(QVBoxLayout* myVerticalLayout)
{
   QWidget* Form = new QWidget();
   Ui::Form* itemWidget = new Ui::Form();
   itemWidget->setupUi(Form);
   QVBoxLayout* itemLayout = new QVBoxLayout();
   Form->setLayout(itemLayout);
   itemWidget->radioButton->setText(QString("Tada-%1").arg(++i));
//   itemWidget->label->setText(QString("Tada-SubText-%1").arg(i));
   itemWidget->label_2->setText(QString("Tada-SubText-%1").arg(i));
//   itemLayout->addWidget(CreateRadioButtonItem());
//   itemLayout->addWidget(CreateRadioButtonItemSubText());

   myVerticalLayout->addWidget(Form);
//   myVerticalLayout->insertStretch(i,1);
}

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
   myVerticalLayout->setSpacing(0);
   myVerticalLayout->setAlignment(Qt::AlignTop);

//   myVerticalLayout->addWidget(CreateRadioButtonItem());
//   myVerticalLayout->addWidget(CreateRadioButtonItem());

   for(int j = 0; j < 2; j++)
   {
      CreateLayoutItem(myVerticalLayout);
   }

//   QSpacerItem* spacer = new QSpacerItem(40, 40, QSizePolicy::Fixed, QSizePolicy::Expanding);
//   myVerticalLayout->addItem(spacer);
//   myVerticalLayout->addStretch(8);

   setCentralWidget(myVerticalLayoutWidget);
}

MainWindow::~MainWindow()
{
   delete ui;
}

QRadioButton* MainWindow::CreateRadioButtonItem()
{
   i++;
   QString rbText = QString("Item-%1").arg(i);
   QRadioButton* rb = new QRadioButton(rbText);
   return rb;
}

QLabel* MainWindow::CreateRadioButtonItemSubText()
{
   QString rbText = QString("ItemSubText-%1").arg(i);

   QLabel* l = new QLabel("SubText");
   return l;
}

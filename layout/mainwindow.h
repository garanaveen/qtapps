#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QLabel>
#include <QVBoxLayout>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();

   void CreateLayoutItem(QVBoxLayout* myVerticalLayout);
private:
   Ui::MainWindow *ui;
QRadioButton* CreateRadioButtonItem();
QLabel* CreateRadioButtonItemSubText();
};

#endif // MAINWINDOW_H

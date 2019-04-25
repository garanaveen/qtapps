#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <thread>
#include <QFuture>
#include <QFutureWatcher>
#include <QThreadPool>
#include <qtconcurrentrun.h>



class TestQtConcurrent : public QObject
{
   Q_OBJECT

public:
   void TestQtConcurrentUsage()
   {
      QThreadPool* threadPool = QThreadPool::globalInstance();
      connect(this, &QFutureWatcher<QStringList>::finished, this, &TestQtConcurrent::PrintResult);
      Future = QtConcurrent::run(threadPool, this, &TestQtConcurrent::TimeTakingFunction);
   }

private:
   QStringList TimeTakingFunction()
   {
      QStringList list;
      list.push_back("string1");
      list.push_back("string2");
      return list;
   }

   void PrintResult()
   {
      List = Future.result();
      for (auto str : List)
      {
         qDebug() << str;
      }
   }

   QStringList List;
   QFutureWatcher<QStringList> FutureWatcher;
   QFuture<QStringList> Future;
};


int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   qDebug() << QT_VERSION_STR ;

   //    return a.exec();
   return 0;
}

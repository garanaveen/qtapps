#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <thread>

void CrashMe()
{
   QObject* pBadObject = NULL;
   pBadObject->objectName();
}

int getRandomNumberUnder10()
{
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> uniform_dist(1,10);
    int mean = uniform_dist(e);
    qDebug() << "mean : " << mean;
    return mean;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "crashtest";

    std::this_thread::sleep_for(std::chrono::seconds(getRandomNumberUnder10()));

    CrashMe();
//    return a.exec();
    return 0;
}

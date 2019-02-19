#ifndef TESTQPROCESS_H
#define TESTQPROCESS_H

#include <QProcess>
#include "processlauncher.h"

class QString;
class QStringList;

class TestQProcess : public QObject
{
    Q_OBJECT
public:
    explicit TestQProcess(QObject* parent=0);
//    void StartProcess();
void StartProcess(const QString& program, const QStringList &arguments);
    QString GenerateFileName(const QString &appName);
    void Cleanup();
private:
    QString combineProgramAndArguments(const QString &program, const QStringList &arguments);
//    QProcess ProcessObj;
};

#endif // TESTQPROCESS_H

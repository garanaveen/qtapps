#ifndef TESTQPROCESS_H
#define TESTQPROCESS_H

class QString;
class QStringList;

class TestQProcess
{
public:
    TestQProcess();
    void StartProcess();
    void GenerateFileName(const QString &appName);
    void Cleanup();
private:
    QString combineProgramAndArguments(const QString &program, const QStringList &arguments);
};

#endif // TESTQPROCESS_H

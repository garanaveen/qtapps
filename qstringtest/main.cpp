#include <QDebug>
#include <QString>

const char* dummy_char()
{
    return "Some const string";
}

std::string dummy_str()
{
    return "Some std string";
}

int main()
{
    qDebug() << QString("%1").arg(dummy_char()); //char* works as is.
    qDebug() << QString("%1").arg(dummy_str().c_str()); //std::string needs to be converted to char*

    return 0;
}

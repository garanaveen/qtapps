//daig/_Tools/WindowTest/main.cpp

#include <QVector>

int main()
{
   int* p = new int[3];
   QVector<int> vec;
   vec.resize(100);
   p[6] = 1024;
   delete[] p;
   return 0;
}


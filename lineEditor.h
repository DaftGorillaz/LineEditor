#ifndef LINEEDITOR_H
#define LINEEDITOR_H
#include "intSLList.h"

class lineEditor
{
  private:
    IntSLList list1;
  public:
    lineEditor();
    void insertLine(int n);
    void deleteLine(int n, int m);
    void listLine(int n, int m);
    void append();
    void exit(string fileName);
};

#endif // LINEEDITOR_H

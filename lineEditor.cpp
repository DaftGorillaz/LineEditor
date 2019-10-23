#include "lineEditor.h"
#include "intSLList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

lineEditor::lineEditor()
{
  list1.counter();
}

void lineEditor::listLine(int n, int m)
{
  cout << list1;
}


void lineEditor::insertLine(int startLine)
{
  //for(int = i; i < n; i++)
  cout << "it works bitch" << endl;
}

void lineEditor::append()
{

}

void lineEditor::deleteLine(int n, int m)
{
    /*
  do
  {
    list1.deleteNode();
  }
  while(n <= m);
  */
}

void lineEditor::exit(string fileName)
{
  ofstream saveFile;
  saveFile.open(fileName.c_str(), fstream::out);
  saveFile << list1;
  saveFile.close();
}

#include <iostream>
#include "intSLList.h"
#include "stringSLList.h"
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    StringSLList textFile;

    string line;
    fstream text;
    string fileName = argv[1];
    int lineCounter = 0, TotalLines = 0;

    text.open(fileName.c_str(), ios::in | ios::out | ios::app);

    if(text.peek() == std::ifstream::traits_type::eof())
    {
      lineCounter = 1;
      TotalLines++;
      cout << lineCounter << ">";
    }
    else
    {
      do
      {
        getline(text,line);
        lineCounter++;
        TotalLines++;
        if(!text.eof())
        {
          cout << lineCounter << ">" << line << endl;
          textFile.addToTail(line);
        }
        else
          cout << lineCounter << ">";

      }
      while(!text.eof());
    }

    GoHereToAddLines:

    getline(cin,line);
    stringstream fullLine(line);
    string command;
    int n = 0;
    int m = 0;

    if(line[1] == ' ' || line[1] == 0)
    {
      fullLine >> command >> n >> m;
      if(m == 0)
      {
        m = n;
      }
      else if(n > m)
      {
        cout << "Invalid Input." << endl;
        goto GoHereToAddLines;
      }
      if(line[0] == 'E')
      {
        //Exit and Save
        fstream Save;
        Save.open(fileName.c_str(), fstream::out | fstream::in);
        Save << textFile;
        Save.close();
      }

      else if (line[0] == 'A')
      {
        //Appends line
        lineCounter = TotalLines;
        cout << lineCounter << ">";
        goto GoHereToAddLines;
      }
      else if (line[0] == 'I')
      {
        //inserts line
        string newLine;

        lineCounter = n;
        cout << lineCounter << ">";
        //loops
        do
        {
          getline(cin, newLine);
          textFile.insertNode(n, newLine);
          lineCounter++;
          n++;
          cout << lineCounter << ">";
        }
        while(newLine[1] == 0 || newLine[1] == ' ');

        lineCounter++;

        goto GoHereToAddLines;
      }
      else if (line[0] == 'D')
      {
        //Delete Line
        if(m > n)
        {
          for (int i = n; i <= m; i++)
          {
            textFile.delete_position(n);
            lineCounter--;
          }
        }
        else if (n == 0)
        {
          textFile.delete_position(lineCounter - 1);
          lineCounter--;
        }
        else
        {
          textFile.delete_position(n);
          lineCounter--;
        }
        cout << lineCounter << ">";
        goto GoHereToAddLines;
      }
      else if (line[0] == 'L')
      {
        if(m > n)
        {
          for (int i = n; i <= m; i++)
          {
            lineCounter = n;
            cout << lineCounter << ">";
            textFile.display(n);
            n++;
          }
          lineCounter = TotalLines;
        }
        else if (n == 0)
        {
          n = 1;
          while(n != TotalLines)
          {
            lineCounter = n;
            cout << lineCounter << ">";
            textFile.display(n);
            n++;
          }
          lineCounter = TotalLines;
        }
        else
        {
          lineCounter = n;
          cout << lineCounter << ">";
          textFile.display(n);
          lineCounter = TotalLines;
        }
        cout << lineCounter << ">";
        goto GoHereToAddLines;
      }
    }
    else
    {
      textFile.addToTail(line);
      TotalLines++;
      lineCounter++;
      cout << lineCounter << ">";
      goto GoHereToAddLines;
    }
}

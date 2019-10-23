#include <iostream>

using namespace std;

#ifndef STRINGSLLIST_H
#define STRINGSLLIST_H

class StringSLLNode
{
  public:
    StringSLLNode()
    {
      next = 0;
    }
    StringSLLNode(string el, StringSLLNode *ptr = 0)
    {
      info = el; next = ptr;
    }
    string info;
    StringSLLNode *next;
};

class StringSLList
{
  private:
    StringSLLNode *head, *tail;

  public:
    StringSLList()
    {
      head = tail = 0;
    }
    bool isEmpty()
    {
      return head == 0;
    }
    void addToHead(string);
    void addToTail(string);
    string deleteFromHead();
    string deleteFromTail();
    bool isInList(string) const;
    void deleteNode(string);
    friend ostream& operator << (ostream& out, StringSLList node);
    void display(int n);
    void insertNode(int n, string value);
    void delete_position(int n);
};

#endif // STRINGSLLIST_H

#include <iostream>

using namespace std;

#ifndef INTSLLIST_H
#define INTSLLIST_H


class IntSLLNode
{
  public:
    IntSLLNode()
    {
      next = 0;
    }
    IntSLLNode(int el, IntSLLNode *ptr = 0)
    {
      info = el; next = ptr;
    }
    int info;
    IntSLLNode *next;
};

class IntSLList
{
  private:
    IntSLLNode *head, *tail;

  public:
    IntSLList()
    {
      head = tail = 0;
    }
    bool isEmpty()
    {
      return head == 0;
    }
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead();
    int deleteFromTail();
    bool isInList(int) const;
    void deleteNode(int);
    friend ostream& operator << (ostream& out, IntSLList node);
    void display();
    int counter();
};

#endif // INTSLLIST_H

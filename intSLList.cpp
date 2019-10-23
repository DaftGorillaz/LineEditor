#include "intSLList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//element is the info to be added to head of list.
void IntSLList::addToHead(int element)
{
  head = new IntSLLNode(element, head);
  if (tail == 0)
  {
    tail = head;
  }
}

void IntSLList::addToTail(int element)
{
  if (tail != 0)
  { //if list is not empty
    tail->next = new IntSLLNode(element);
    tail = tail->next;
  }
  else
    head = tail = new IntSLLNode(element);
}

int IntSLList::deleteFromHead()
{
  int el = head->info;
  IntSLLNode *tmp = head;
  if (head == tail)
    head = tail = 0;
  else
    head = head->next;
  delete tmp;
  return el;
}

int IntSLList::deleteFromTail()
{
  int el = tail->info;
  if (head == tail)
  {
    delete head;
    head = tail = 0;
  }
  else
  {
    IntSLLNode *tmp;
    for (tmp = head; tmp->next != tail; tmp = tmp->next);
    delete tail;
    tail = tmp;
    tail->next = 0;
  }
  return el;
}

void IntSLList::deleteNode(int el)
{
  if (head != 0)
  {
    if (head == tail && el == head->info)
    {
      delete head;
      head = tail = 0;
    }
    else if (el == head->info)
    {
      IntSLLNode *tmp = head;
      head = head->next;
      delete tmp;
    }
    else
    {
      IntSLLNode *pred, *tmp;
      for (pred = head, tmp = head->next; tmp != 0 && !(tmp->info == el); pred = pred->next, tmp = tmp->next);
      if (tmp != 0)
      {
        pred->next = tmp->next;
        if (tmp == tail)
        {
          tail = pred;
        }
        delete tmp;
      }
    }
  }
}

ostream& operator << (ostream& out, IntSLList node)
{
  IntSLLNode* p = node.head;
  while(p != 0)
  {
    out << p->info << endl;
    p = p->next;
  }
  return out;
}

//displays the list
void IntSLList::display()
{
  IntSLLNode* p = head;
  while(p != 0)
  {
    cout << p->info << endl;
    p = p->next;
  }
}

int IntSLList::counter()
{
  IntSLLNode* p = head;
  int i = 0;
  while(p != 0)
  {
    i++;
  }
  return i;
}

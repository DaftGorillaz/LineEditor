#include "stringSLList.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;

//element is the info to be added to head of list.
void StringSLList::addToHead(string element)
{
  head = new StringSLLNode(element, head);
  if (tail == 0)
  {
    tail = head;
  }
}

void StringSLList::addToTail(string element)
{
  if (tail != 0)
  { //if list is not empty
    tail->next = new StringSLLNode(element);
    tail = tail->next;
  }
  else
    head = tail = new StringSLLNode(element);
}

string StringSLList::deleteFromHead()
{
  string el = head->info;
  StringSLLNode *tmp = head;
  if (head == tail)
    head = tail = 0;
  else
    head = head->next;
  delete tmp;
  return el;
}

string StringSLList::deleteFromTail()
{
  string el = tail->info;
  if (head == tail)
  {
    delete head;
    head = tail = 0;
  }
  else
  {
    StringSLLNode *tmp;
    for (tmp = head; tmp->next != tail; tmp = tmp->next);
    delete tail;
    tail = tmp;
    tail->next = 0;
  }
  return el;
}

void StringSLList::deleteNode(string el)
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
      StringSLLNode *tmp = head;
      head = head->next;
      delete tmp;
    }
    else
    {
      StringSLLNode *pred, *tmp;
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

ostream& operator << (ostream& out, StringSLList node)
{
  StringSLLNode* p = node.head;
  while(p != 0)
  {
    out << p->info << endl;
    p = p->next;
  }
  return out;
}

//displays the list
void StringSLList::display(int n)
{

  StringSLLNode* p = head;
  for(int i = 1; i < n; i++)
  {
    p = p->next;
  }
  cout << p->info << endl;

}

void StringSLList::insertNode(int n, string value)
{
  StringSLLNode *pre=new StringSLLNode;
  StringSLLNode *cur=new StringSLLNode;
  StringSLLNode *newNode=new StringSLLNode;
  cur=head;
  for(int i = 1 ; i < n; i++)
  {
    pre=cur;
    cur=cur->next;
  }
  newNode->info=value;
  pre->next=newNode;
  newNode->next=cur;
}

void StringSLList::delete_position(int n)
{
  StringSLLNode *current=new StringSLLNode;
  StringSLLNode *previous=new StringSLLNode;
  current=head;
  for(int i = 1; i < n; i++)
  {
    previous=current;
    current=current->next;
  }
  previous->next=current->next;
}

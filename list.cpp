#pragma once 
#include <fstream> 
using namespace std; 
template <class T> 
class MyList 
{ 
 class Node { 
 public: 
  T info; 
  Node* next; 
  Node(T a): info(a) {} 
  Node(T a, Node* next): info(a), next(next){} 
  friend ostream& operator<<(ostream& os, Node* h) { 
   return os<< h->info; 
  } 
 }; 
public: 
 Node* head = nullptr; 
 Node* tail = nullptr; 
 MyList(); 
 void add(T a); 
 void addEnd(T a); 
 T getBegin(); 
 T getEnd(); 
 bool isEmpty(); 
 friend ostream& operator<<(ostream& os, MyList<T>& l) { 
  for (Node* t = l.head; t; t = t->next) os << t->info << "->"; 
  return os; 
 } 
}; 
template<class T> 
class MyStack :public MyList<T> { 
public: 
 MyStack(){} 
 MyStack(T a): MyList(){} 
 void push(T a) { 
  this->addEnd(a); 
 } 
 T pop() { 
  return this->getEnd(); 
 } 
 /*friend ostream& operator << (ostream& os, MyStack<T> st) { 
  os << (MyList<T>)st; 
  return os; 
 }*/ 
}; 
template<class T> 
class MyQueue :public MyList<T> { 
public: 
 void push(T a) { 
  this->addEnd(a); 
 } 
 T pop() { 
  this->getEnd(); 
 } 
}; 
template<class T> 
inline MyList<T>::MyList() 
{ 
 Node* h; 
 while (head) { 
  h = head; 
  head = head->next; 
  delete h; 
 } 
 head = tail = nullptr; 
} 
template<class T> 
inline void MyList<T>::add(T a) 
{ 
 Node* t = new Node(a, head); 
 if (!head) head = tail = t; 
 else head = t; 
} 
 
template<class T> 
inline void MyList<T>::addEnd(T a) 
{ 
 Node* t = new Node(a); 
 if (!head) { 
  head = tail = t; return; 
 } 
 tail->next = t; 
 tail = t; 
 
} 
 
template<class T> 
inline T MyList<T>::getEnd() { 
 Node* t = tail; 
 T help = tail->info; 
 if (tail == head) { head = tail = nullptr; } 
 else{ 
  Node* h; 
  for (h = head; h->next && h->next->next; h = h->next); 
  tail = h; 
  tail->next = nullptr; 
  delete h->next; 
 } 
 return help; 
} 
 
template<class T> 
inline T MyList<T>::getBegin() { 
 T help = head->info; 
 Node* h = head; 
 if (tail == head) head = tail = nullptr; 
 else 
 head = head->next; 
 delete h; 
 return help; 
}

/*Title: Lab11.cpp
Author: Jeremy Dixon
Date: 11/9/2017
Description: This is the lab 11 file which practices the copy constructor and the overloaded
assignment operators.
*/

#include <iostream>
#include <string>
using namespace std;

struct Node{
  int m_data;
  Node* m_next;
};

class LinkedList{
 public:
  LinkedList(); //Default constructor
  LinkedList(const LinkedList& other); //Copy Constructor
  ~LinkedList(); //Destructor
  void ClearList(); //Deletes all nodes in list
  void InsertBegin(int newData); //Insertion Function
  void InsertEnd(int newData); //Insertion Function
  void PrintList(); //Print Function
  void DeleteEnd(); //Delete Function
  LinkedList &operator=(const LinkedList& other); //Overloaded Assignment Operator
 private:
  Node* m_head; //Private Member Variable
};


LinkedList::LinkedList(){ //Default constructor
  m_head = NULL;
}

//Write the Copy Constructor here





LinkedList::~LinkedList(){ //Destructor
  ClearList();
}

//Write the ClearList Function (used by the destructor) here




void LinkedList::InsertEnd(int newData){ //Insertion Function
  Node *newNode = new Node();
  newNode->m_data = newData;
  newNode->m_next = NULL;
  if(m_head == NULL)
    m_head = newNode;
  else {
    Node * temp = m_head;
    while(temp->m_next != NULL){
      temp = temp->m_next;
    }
    temp->m_next = newNode;
  }
}

void LinkedList::PrintList(){ //Print Function
  Node *temp = m_head;
  while(temp != NULL){
    cout << temp->m_data << "-->";
    temp = temp->m_next;
  }
  cout << "END" << endl;
}

void LinkedList::DeleteEnd(){ //Delete Function
  if (m_head->m_next == NULL) {
    delete m_head;
    m_head = NULL;
  }
  else {
    Node *cur = m_head;
    Node *next = m_head->m_next;
    while (cur->m_next != NULL) {
      next = cur;
      cur = cur->m_next;
    }
    delete cur;
    next->m_next = NULL;
  }
}

//Write the overloaded assignment operator here


int main () {
  cout << "Linked List 1:" << endl;
  cout << "Testing Constructor" << endl;
  LinkedList ll1;
  ll1.InsertEnd(10);
  ll1.InsertEnd(15);
  ll1.InsertEnd(20);
  ll1.PrintList();
  cout << endl;
  
  cout << "Linked List 2:" << endl;
  cout << "Testing Copy Constructor" << endl;
  LinkedList ll2(ll1);
  ll2.InsertEnd(25);
  ll2.PrintList();
  cout << endl;
  
  cout << "Clearing Linked List 1" << endl;
  ll1.ClearList();
  cout << "Outputting Linked List 2 (to make sure deep copy)" << endl;
  ll2.PrintList();
  cout << endl;
  
  cout << "Testing Assignment Operator" << endl;
  ll1 = ll2;
  cout << "Outputting Linked List 1" << endl;
  ll1.PrintList();
  return 0;
}

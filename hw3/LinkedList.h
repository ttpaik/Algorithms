//
//  LinkedList.h
//
//  Copyright © Tali Moreshet. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

using namespace std;

template <class T = int>
class Node {
public:
    Node();                                         // default constructor
    Node(const T& data, Node<T>* next = nullptr);   // donstructor
    T data;                                         // node data
    Node<T>* next;                                  // node next pointer
};

template <class T = int>
class LinkedList {
public:
    LinkedList();                                   // constructor
    ~LinkedList();                                  // destructor
    T deleteFromHead();                             // removes and returns content of head
    T deleteFromTail();                             // removes and returns content of tail
    void deleteNode(T data);                        // removes node with specified data
    void InsertToHead(T data);                      // insert node with data at the head
    void InsertToTail(T data);                      // insert node with data at the tail
    int getSize();                                  // returns size of linked list
    void print();                                   // prints linked list
private:
    Node<T>* head;                                  // head of linked list
};


template <class T = int>
class StackFromList {
public:
    StackFromList();
    ~StackFromList();
    void push(T data);
    T pop();
    bool isEmpty();
private:
    Node<T>* topstack;
};


template <class T = int>
class QueueFromList {
public:
    QueueFromList();
    ~QueueFromList();
    void enqueue(T data);
    T dequeue();
    bool isEmpty();
private:
    Node<T>* queue;
};
/******* From here down is the content of the LinkedList.cpp file: ***********************/

 /* Implementation of Node */

 // default constructor
 template<class T>
 Node<T>::Node()
 {
 }
 
 // constructor
 template<class T>
 Node<T>::Node(const T& data, Node<T>* next)
 {
     this->data = data;
     this->next = next;
 }
 
 /* Implementation of linked list */

 // constructor
 template <class T>
 LinkedList<T>::LinkedList()
 {
     head = nullptr;
 }

 // destructor
 template <class T>
 LinkedList<T>::~LinkedList()
 {
    /*** to be implemented ***/
     while (head != nullptr) {
         Node<T>* des = head;
         head = head->next;
         delete(des);
     }
 }

 template <class T>
 T LinkedList<T>::deleteFromHead()
 {
     /*** to be implemented ***/
     Node<T>* imsi = head;
     if (head->next == nullptr) {
         T data = head->data;
         head = nullptr;
         return data;
     }

     else {
         head = head->next;
         T data = imsi->data;
         delete imsi;
         return data;
     }
 }


 template <class T>
 T LinkedList<T>::deleteFromTail()
 {
     /*** to be implemented ***/
     Node<T>* imsi = head;
     if (head->next == nullptr) {
         T data = head->data;
         head = nullptr;
         return data;
     }

     while (imsi->next->next != nullptr) {
         imsi = imsi->next;
     }
     T data = imsi->next->data;
     delete imsi->next;
     imsi->next = nullptr;
     return data;

 }
 

 template <class T>
 void LinkedList<T>::deleteNode(T data)
 {
    /*** to be implemented ***/
     Node<T>* imsi = head;
     Node<T>* imsi2 = head;
     if (head->data == data) {
         head = head->next;
     }

     while (imsi->next != nullptr) {
         
         if (imsi->next->data == data) {
             imsi2 = imsi->next->next;
             delete imsi->next;
             imsi->next = imsi2;
         }

         else
             imsi = imsi->next;
     }
 }
 

 template <class T>
 void LinkedList<T>::InsertToHead(T data)
 {
     Node<T> * newNode = new Node<T>(data, nullptr);
     
     if (head == nullptr)
         head = newNode;
     else
     {
         newNode->next = head;
         head = newNode;
     }
 }


 template <class T>
 void LinkedList<T>::InsertToTail(T data)
 {
     /*** to be implemented ***/
     Node<T>* newNode = new Node<T>(data, nullptr);
     Node<T>* imsi = head;

     if (imsi == nullptr) {
         head = newNode;
     }

     else {
         while (imsi->next != nullptr) {
             imsi = imsi->next;
         }
         imsi->next = newNode;
     }
 }


 template <class T>
 int LinkedList<T>::getSize()
 {
     /*** to be implemented ***/
     int lsize = 0;
     Node<T>* imsi = head;
     if (imsi == nullptr) {
         return lsize;
     }
     else {
         while (imsi->next != nullptr) {
             imsi = imsi->next;
             lsize++;
         }
         lsize++;
         return lsize;
     }
 }


 template <class T>
 void LinkedList<T>::print()
 {
     if (head == nullptr)
     {
         cout << "Linked list is empty" << endl;;
         return;
     }
     
     cout << head->data << " ";
     
     if (head->next == nullptr)
     {
         cout << endl;
         return;
     }
 
     Node<T>* currNode = head->next;
     Node<T>* prevNode = head;
 
     
     while (currNode->next != nullptr)
     {
         cout << currNode->data << " ";
         prevNode = currNode;
         currNode = currNode->next;
     }
 
     cout << currNode->data << endl;
     return;
 }
     
     

 // PROBLEM 3B ---------------------------------------------------------------------


 template <class T>
 StackFromList<T>::StackFromList() {
     topstack = nullptr;
 }

 template <class T>
 StackFromList<T>::~StackFromList() {
     while (topstack != nullptr) {
         Node<T>* des = topstack;
         topstack = topstack->next;
         delete(des);
     }
 }

 template <class T>
 void StackFromList<T>::push(T data) {
     Node<T>* newNode = new Node<T>(data, nullptr);
     Node<T>* imsi = topstack;
     if (topstack == nullptr) {
         topstack = newNode;
     }
     else {
         while (imsi->next != nullptr)
             imsi = imsi->next;
         imsi->next = newNode;
     }
 }

 template <class T>
 T StackFromList<T>::pop() {
     Node<T>* imsi = topstack;
     if (imsi->next == nullptr) {
         T data = topstack->data;
         topstack = nullptr;
         return data;
     }

     while (imsi->next->next != nullptr) {
         imsi = imsi->next;
     }
     T data = imsi->next->data;
     delete imsi->next;
     imsi->next = nullptr;
     return data;
 }

 template <class T>
 bool StackFromList<T>::isEmpty() {
     return topstack == nullptr;
 }
 

 // PROBLEM 3C ---------------------------------------------------------------------


 template <class T>
 QueueFromList<T>::QueueFromList() {
     queue = nullptr;
 }

 template <class T>
 QueueFromList<T>::~QueueFromList() {
     while (queue != nullptr) {
         Node<T>* des = queue;
         queue = queue->next;
         delete(des);
     }
 }

 template <class T>
 void QueueFromList<T>::enqueue(T data) {
     Node<T>* newNode = new Node<T>(data, nullptr);
    
     if (queue == nullptr)
         queue = newNode;
     else
     {
         newNode->next = queue;
         queue = newNode;
     }
 }

 template <class T>
 T QueueFromList<T>::dequeue() {
     Node<T>* imsi = queue;
    
     if (queue->next == nullptr) {
         T data = queue->data;
         queue = nullptr;
         return data;
     }

     while (imsi->next->next != nullptr) {
         imsi = imsi->next;
     }
     T data = imsi->next->data;
     delete imsi->next;
     imsi->next = nullptr;
     return data;
 }


 template <class T>
 bool QueueFromList<T>::isEmpty() {
     return queue == nullptr;
 }

#endif /* LinkedList_h */
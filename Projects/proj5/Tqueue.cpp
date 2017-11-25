#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue
  void enqueue(T data); //Adds item to queue (to back)
  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  void dequeue(T &); //Removes item from queue (from front)
  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve front (does not remove it)
  void queueFront(T &);    // Retrieve front (does not remove it)
  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0
  //Name: isFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int isFull(); //Returns 1 if queue is full else 0
  //Name: size
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue
  int size(); //Returns size of queue
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//**** Add class definition below ****

// Tqueue
// Constructor for Tqueue class
template <class T, int N>
Tqueue<T, N>::Tqueue()
{
    m_data = new T[N];
    m_back = m_front = N - 1;
}

// Tqueue
// Copy constructor for Tqueue class
template <class T, int N>
Tqueue<T, N>::Tqueue(const Tqueue<T, N> &x) : m_back(x.m_back), m_data(new T[N]), m_front(x.m_front) {
    for (int i = 0; i < N; i++)
        m_data[i] = x.m_data[i];
}


// ~Tqueue
// Deconstructor for Tqueue
template <class T, int N>
Tqueue<T, N>::~Tqueue()
{
    delete[] m_data;
}


// Enqueue
// Add object<T> to back of queue
template <class T, int N>
void
Tqueue<T, N>::enqueue(T data)
{
    m_data[m_back--] = data;
}


// Dequeue
// Remove object<T> from the front of queue
template <class T, int N>
void
Tqueue<T, N>::dequeue(T &t)
{
    t = m_data[m_front--];
    
    if (isEmpty())
        m_front = m_back = N - 1;
}


// queueFront
// Display the front of the queue without removing it
template <class T, int N>
void
Tqueue<T, N>::queueFront(T &t)
{
    t = m_data[m_front];
}


// isEmpty
// Returns 1 if empty, 0 if not
template <class T, int N>
int
Tqueue<T, N>::isEmpty()
{
    return (m_front == m_back) ^ 0;
}

// isFull
// returns 1 if full, 0 if not
template <class T, int N>
int
Tqueue<T, N>::isFull()
{
    return (!m_back) ^ 0;
}

// size
// returns size of the queue
template <class T, int N>
int
Tqueue<T, N>::size()
{
    return m_front - m_back;
}

// operator=
// Overrides = operator for Tqueue class
template <class T, int N>
Tqueue<T, N> &
Tqueue<T, N>::operator=(Tqueue<T, N> y)
{
    m_back = y.m_back;
    m_front = y.m_front;
    m_data = new T(N);
    for (int i = 0; i < N; i++)
        m_data[i] = y.m_data[i];
    return *this;
    
}


// operator[]
// Overrides [] operator for Tqueue class
template <class T, int N>
T &
Tqueue<T, N>::operator[](int x)
{
    return m_data[m_front-x];
}


#endif


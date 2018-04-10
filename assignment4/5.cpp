#include <iostream>
#include <fstream>
#include <string>
#include "dyncharqueue.h"
using namespace std;

void compare(DynCharQueue&, DynCharQueue&);

int main(){


   	string input; // To hold file input
  	fstream nameFileOne; // File stream object
    fstream nameFileTwo;
    DynCharQueue fileOne;
    DynCharQueue fileTwo;

  	// Open the file in input mode.
  	nameFileOne.open("checkfile1.txt", ios::in);
    nameFileTwo.open("checkfile2.txt", ios::in);
  	// If the file was successfully opened, continue.
  	if (nameFileOne)
  	{
  		char c;//Read an item from the file.
  		while (nameFileOne.get(c)){
      fileOne.enqueue(c);
  		// Read the file contents.
    }
  	}
    if (nameFileTwo)
    {
      char a;//Read an item from the file.
  		while (nameFileTwo.get(a)){
      fileTwo.enqueue(a);
}

}


compare(fileOne, fileTwo);



return 0;
}









//************************
// Constructor           *
//************************
DynCharQueue::DynCharQueue()
{
   front = NULL;
   rear = NULL;
   numItems = 0;
  //testline cout << "initialized" << endl;
}

//************************
// Destructor            *
//************************

DynCharQueue::~DynCharQueue()
{
   clear();
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************

void DynCharQueue::enqueue(char num)
{
   QueueNode *newNode;

    newNode = new QueueNode;
    newNode->value = num;
    newNode->next = NULL;
    if (isEmpty())
    {
       front = newNode;
       rear = newNode;
    }
    else
    {
       rear->next = newNode;
       rear = newNode;
    }
    numItems++;
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************

void DynCharQueue::dequeue(char &num)
{
   QueueNode *temp;

   if (isEmpty())
   {
      cout << "The queue is empty.\n";
      exit(1);
   }
    else
    {
       num = front->value;
       temp = front;
       front = front->next;
       delete temp;
       numItems--;
    }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************

bool DynCharQueue::isEmpty()
{
    bool status;

    if (numItems > 0)
       status = false;
    else
       status = true;
    return status;
}

char DynCharQueue::getFront(){
  return front->value;
}


//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************

void DynCharQueue::clear()
{
    char value;   // Dummy variable for dequeue

    while(!isEmpty())
       dequeue(value);
}

void compare(DynCharQueue &a, DynCharQueue &b){
    if(a.getFront() == b.getFront()){
      // testline cout << "the same char" << " " << a.getFront() << endl;
      char match = a.getFront();
      a.dequeue(match);
      b.dequeue(match);
      if(a.isEmpty() || b.isEmpty()){
        cout << "match detected" << endl;
      }
      else
        compare(a, b);
    }
    else if(a.getFront() != b.getFront()){
      cout << "the files don't match" << endl;
    }

  }

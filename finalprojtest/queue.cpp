//queue.cpp
//Walker Gray

#include "queue.h"

using namespace std;

Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
	size = 0;
}

Queue::~Queue()
{
	
}

void Queue::enqueue(Card* c)
{
	Node* newNode = new Node;
	newNode -> value = c;
	if(isEmpty())
	{
		newNode -> next = nullptr;
		newNode -> last = nullptr;
		rear = newNode;
		front = newNode;
	} else {
		newNode -> last = rear;
		newNode -> next = nullptr;
		rear -> next = newNode;
		rear = newNode;
	}
	size++;
}

void Queue::dequeue(Card* c)
{
	if(isEmpty())
	{
		cout << "This queue is empty" << endl;
		c = new Card();
	} else {
		Node* oldNode = new Node;
		oldNode = front;
		if(size > 1) {
			front = oldNode -> next;
			front -> last = nullptr;
		} else {
			front = nullptr;
		}
		size--;
		Card* temp = oldNode -> value;
		*c = *(static_cast<Monster*>(temp));;
		delete oldNode;
	}
}

bool Queue::isEmpty()
{
	return (size <= 0);
}

int Queue::length()
{
	return size;
}
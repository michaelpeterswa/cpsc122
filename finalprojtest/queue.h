//queue.h
//walker gray

#ifndef QUEUE_H
#define QUEUE_H

#include "monster.h"

using namespace std;

class Queue {
	struct Node
	{
		Card* value;
		Node* next;
		Node* last;
	};

	public:
		Queue();
		~Queue();
		void enqueue(Card* c);
		void dequeue(Card* c);
		bool isEmpty();
		int length();

	private:
		Node* front;
		Node* rear;
		int size;
};

#endif

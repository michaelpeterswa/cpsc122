#ifndef DYNCHARQUEUE_H
#define DYNCHARQUEUE_H

class DynCharQueue
{
private:
	struct QueueNode
	{
		char value;
		QueueNode *next;
	};

	QueueNode *front;
	QueueNode *rear;
	int numItems;
public:
	DynCharQueue();
   ~DynCharQueue();
   void enqueue(char);
   void dequeue(char &);
   bool isEmpty();
   bool isFull();
   void clear();
	 char getFront();
};

#endif

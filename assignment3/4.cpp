#include <iostream>
using namespace std;

class NumberList
{

	private:
	// Declare a structure for the list
		struct ListNode
		{
			double value; // The value in this node
			struct ListNode *next; // To point to the next node
		};

		ListNode *head; // List head pointer

	public:
	// Constructor
		NumberList()
			{ 	head = nullptr; }

	// Linked list operations
		void appendNode(double);
		void insertNode(double);
		void deleteNode(double);
    int search(double);
		void displayList() const;
};

int main(){
  NumberList alpha;

  alpha.appendNode(3.4);
  alpha.appendNode(5.3);
  alpha.appendNode(7.9);
  alpha.appendNode(10.5);
  alpha.appendNode(16.7);
  cout << "current linked list:" << endl;
  alpha.displayList();
  cout << endl;
  alpha.deleteNode(3);
  cout << "linked list with deletion of position 3:" << endl;
  alpha.displayList();

  cout << endl;
  cout << "current position search for '7.9' :" << endl;
  cout << alpha.search(7.9) << endl;
  return 0;
}

void NumberList::appendNode(double num)
{
	ListNode *newNode; 		// To point to a new node
	ListNode *nodePtr; 		// To move through the list

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;
    // If there are no nodes in the list
    // make newNode the first node.

    if (!head)
		head = newNode;
	else 	// Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}


void NumberList::displayList() const {

	ListNode *nodePtr; // To move through the list
// Position nodePtr at the head of the list.
	nodePtr = head;
// While nodePtr points to a node, traverse the list.
	while (nodePtr)
	{

		// Display the value in this node.
		cout << nodePtr->value << endl;
		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}



void NumberList::insertNode(double num)
{
	ListNode *newNode; // A new node
	ListNode *nodePtr; // To traverse the list
	ListNode *previousNode = nullptr; // The previous node

	//Allocate a new node and store num there
	newNode = new ListNode;
    newNode->value = num;

    // If there are no nodes in the list
    //make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else //otherwise insert newNode
	{
		//Position nodePtr at the head of the list
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		//Skip all nodes whose value is less than num.
		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		//If the newnode is to be the 1st in the list, insert it before all other nodes.
 		if (previousNode == nullptr)
 		{
 			head = newNode;
			newNode->next = nodePtr;
 		}
 		else // Otherwise insert after the previous node.
 		{
 			previousNode->next = newNode;
			newNode->next = nodePtr;
 		}
	}
}


int NumberList::search(double num){
  int ctr = 0;
  ListNode *nodePtr; // To move through the list
// Position nodePtr at the head of the list.
  nodePtr = head;
// While nodePtr points to a node, traverse the list.
  while (nodePtr)
  {
    if(nodePtr->value == num){
      return ctr;
    }
    else{
     // Move to the next node.
      nodePtr = nodePtr->next;
    }
    ctr++;
  }
  return -1;
}

void NumberList::deleteNode(double pos){
  ListNode *a = new ListNode;
  ListNode *b = new ListNode;

  a = head;
// While nodePtr points to a node, traverse the list.
  for(int i = 0; i < pos; i++){
    b = a;
    a=a->next;
  }
  b->next=a->next;
}

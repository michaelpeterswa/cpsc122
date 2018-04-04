#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
#include <string>
using namespace std;

class Player{

  private:
    struct ListNode
		{
      string name;
      int lifePoints;
			struct ListNode *next; // To point to the next node
		};

		ListNode *head;


  public:



    Player(){
      cout << "player linked list initialized" << endl;
      head = nullptr;

    }

    void appendNode(string a)
    {
      	ListNode *newNode; 		// To point to a new node
      	ListNode *nodePtr; 		// To move through the list

      	// Allocate a new node and store num there.
      	newNode = new ListNode;
      	newNode->name = a;
        newNode->lifePoints = 8000;
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

    void displayList() const {

      	ListNode *nodePtr; // To move through the list
      // Position nodePtr at the head of the list.
      	nodePtr = head;
      // While nodePtr points to a node, traverse the list.
      	while (nodePtr)
      	{

      		// Display the value in this node.
      		cout << nodePtr->name << endl;
          cout << nodePtr->lifePoints << endl;
          cout << endl;
      		// Move to the next node.
      		nodePtr = nodePtr->next;
      	}
      }

    int search(string name){
        int ctr = 0;
        ListNode *nodePtr; // To move through the list
      // Position nodePtr at the head of the list.
        nodePtr = head;
      // While nodePtr points to a node, traverse the list.
        while (nodePtr)
        {
          if(nodePtr->name == name){
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

    };

#endif

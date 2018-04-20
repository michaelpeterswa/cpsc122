//cardArray.cpp
//Walker Gray
//nearly identical to DeckArrays just with cards, and a few other minor changes

#ifndef CARDARRAY_CPP
#define CARDARRAY_CPP

#include "card.h"

using namespace std;

class CardArray {
	
	struct Node {			//card double linked list node
		Card* card;
		Node* next;
		Node* last;
	};
	
	public:
		
		CardArray()						//null constructor
		{
			size = 0;
			head = nullptr;
			owner = "deckManager";
		}
	
		CardArray(string o)				//default constructor used by deck.shuffle();
		{
			size = 0;
			head = nullptr;
			owner = o;
		}
		
		~CardArray()					//destructor
		{
			Node* curr = head;
			head = nullptr;
			for(int count = 0; count < size; count++)
			{
				Node* temp = curr;
				curr = curr -> next;
				delete temp -> next;
				delete temp;
			}
			size = 0;
		}
		
		void operator=(const CardArray &a)		//overridden assignment operator
		{
			owner = a.owner;
			for(int i = 0; i < a.size; i++)
			{
				Card* c = a[i];
				add(c);
			}
		}
		
		Card* operator[](int i)					//overridden subscript operator for array-like access
		{
			//cout << "1" << endl;
			if(i >= 0 && i <= size)
			{
				//cout << "2" << endl;
				if(i == size) {
					//cout << "3" << endl;
					add(new Card());
					//cout << "5" << endl;
				}
				//cout << "6" << endl;
				Node* curr = head;
				for(int count = 0; count < i; count++)
				{
					//cout << "node " << curr << endl;
					//cout << "card " << (curr -> card) << endl;
					//cout << "last " << (curr -> last) << endl;
					//cout << "next " << (curr -> next) << endl;
					//cout << "[]loop" << endl;
					//cout << (curr -> next) << endl;
					curr = curr -> next;
					//cout << "count: " << count << endl;
				}
				//cout << "ret" << endl;
				//cout << "node " << curr << endl;
				//cout << "card " << (curr -> card) << endl;
				//cout << "last " << (curr -> last) << endl;
				//cout << "next " << (curr -> next) << endl;
				return curr -> card;
			} else {
				//cout << "4" << endl;
				//errorStream/runLog << "Index Out of Bounds" << endl;
				return new Card("null", "null", -1);
			}
		}
		
		Card* operator[](int i) const			//same as above but const for output << operator (why do i even have that on this class it shouldnt be able to be used ever)
		{
			//cout << "ruh roh" << endl;
			if(i >= 0 && i <= size)
			{
				Node* curr = head;
				for(int count = 0; count < i; count++)
				{
					curr = curr -> next;
				}
				return curr -> card;
			} else {
				//errorStream/runLog << "Index Out of Bounds" << endl;
				return new Card("null", "null", -1);
			}
		}
		
		int length()							//"array length" property function, returns size
		{
			return size;
		}
		
		bool isEmpty() {						//returns true if array is empty
			return size <= 0;
		}
		
		string getOwner()						//contains owner name of deck this cardArray was created to assist
		{
			return owner;
		}
		
		void add(Card* c)						//add:append function to append a card to end of list; implicitly called when accessed using subscript[] at index after last element (index = size)
		{
			//add:append
			if(!isEmpty()) {
				Node* incurr = head;
				for(int count = 0; count < size - 1; count++)
				{
					//cout << "loop" << endl;
					incurr = incurr -> next;
				}
				Node* newNode = new Node;
				newNode -> next = nullptr;
				newNode -> card = c;
				newNode -> last = incurr;
				incurr -> next = newNode;
				//cout << "zooweemama" << endl;
			} else {
				Node* newNode = new Node;
				newNode -> next = nullptr;
				newNode -> card = c;
				newNode -> last = nullptr;
				head = newNode;
			}
			size++;
			//cout << "touchdown" << endl;
		}
		
		void add(Card* c, int i)					//add:insert function to insert card at given index, shifting previous element at index and all after it one index further from head. Must be explicitly called
		{
			//add:insert
			if(i >= 0 && i <= size)
			{
				if(i == size) {
					add(c);
				} else if(i == 0) {
					Node* newNode = new Node;
					newNode -> card = c;
					newNode -> next = head -> next;
					newNode -> last = nullptr;
					head = newNode;
					size++;
				} else {
					Node* curr = head;
					for(int count = 0; count < i - 1; count++)
					{
						curr = curr -> next;
					}
					Node* newNode = new Node;
					newNode -> next = curr -> next;
					newNode -> card = c;
					newNode -> last = curr;
					curr -> next = newNode;
					size++;
				}
			} else {
				//ErrFlow/runLog << "Index out of range";
			}
		}
		
		void remove(int i)						//remove element at index i, must be exlicitly called
		{
			if(i >= 0 && i < size)
			{
				if(i == 0) {
					Node* temp = head;
					head = head -> next;
					delete temp -> card;
					delete temp;
				} else {
					Node* curr = head;
					for(int count = 0; count < i - 1; count++)
					{
						curr = curr -> next;
					}
					Node* temp = curr -> next;
					curr -> next = temp -> next;
					delete temp -> card;
					delete temp;					
				}
				size--;
			} else {
				//ErrFlow/runLog << "Index out of range";
			}
		}
		/*
		friend ostream& operator<<(ostream& o, const CardArray &a)		//override of output operator. I don't know why this class should ever be able to use this since a CardArray should not be used outside of shuffle or some other specific task involving manipulating cards around a deck. Deck is required to be a stack so THIS IS NOT TO BE USED AS A DECK
		{
			o << a.owner << endl;
			for(int i = 0; i < a.size; i++)
			{
				o << a[i] << endl;
			}
			return o;
		}
		*/
		
	private:
		Node* head;		//head pointer for linked list array
		int size;		//size field, corresponds to array.length
		string owner;	//owner name for deck this CardArray was created to assist
};

#endif
//deckArray.cpp
//Walker Gray

//DECKARRAY is pretty core to the ease of use I intended. It is supposed to be used nearly identically to an array code-wise, but under the hood it's actually a linked list, thus allowing dynamic size

#ifndef DECKARRAY_CPP
#define DECKARRAY_CPP

#include "deck.cpp"

using namespace std;

class DeckArray {
	struct Node {		//double linked list node
		Deck deck;
		Node* next;
		Node* last;
	};
	
	public:
		
		DeckArray()		//null constructor
		{
			size = 0;
			head = nullptr;
			owner = "deckManager";
		}
	
		DeckArray(string o)		//standard constructor, whether from new user creation or loading from file, this should start empty and be populated with decks
		{
			size = 0;
			head = nullptr;
			owner = o;
		}
		
		~DeckArray()		//DeckArray linked list destructor
		{
			Node* curr = head;
			head = nullptr;
			for(int count = 0; count < size; count++)
			{
				Node* temp = curr;
				curr = curr -> next;
				delete &(temp -> next);
				delete temp;
			}
			size = 0;
		}
		
		void operator=(const DeckArray &a)		//assignment operator. Assigns each deck from right to left (which in turn calls deck and then card assignments)
		{
			owner = a.owner;
			for(int i = 0; i < a.size; i++)
			{
				Deck *d = a[i];
				add(*d);
			}
		}
		
		Deck* operator[](int i)					//subscripting operator override. returns deck at given integer index, which can then be altered or used
		{
			if(i >= 0 && i <= size)
			{
				if(i == size) {
					add(*(new Deck("temp", "deckManager")));
				}
				Node* curr = head;
				for(int count = 0; count < i; count++)
				{
					curr = curr -> next;
				}
				return &(curr -> deck);
			} else {
				//errorStream/runLog << "Index Out of Bounds" << endl;
				return new Deck("null", "deckManager");
			}
		}
		
		Deck* operator[](int i) const		//same as above but this time as a const. required for operator<< function due to parameter DeckArray& being const
		{
			if(i >= 0 && i < size)
			{
				Node* curr = head;
				for(int count = 0; count < i; count++)
				{
					curr = curr -> next;
				}
				return &(curr -> deck);
			} else {
				//errorStream/runLog << "Index Out of Bounds" << endl;
				return new Deck("null", "deckManager");
			}
		}
		
		int length()						//length "property" of  "array"; returns size
		{
			return size;
		}
		
		bool isEmpty() {					//returns true if DeckArray is empty
			return size <= 0;
		}
		
		string getOwner()					//getter for DeckArray owner. Players only need one DeckArray as it is just a data structure for Decks
		{
			return owner;
		}
		
		void add(Deck d)					//add:append function for appending a deck to the end of the list as a new Node. Is implicitly called when attempting to assign a deck to next index after the last element (index = size)
		{
			//add:append
			if(isEmpty()) {
				Node* curr = head;
				for(int count = 0; count < size; count++)
				{
					curr = curr -> next;
				}
				Node* newNode;
				newNode -> next = nullptr;
				newNode -> deck = d;
				curr -> next = newNode;
			} else {
				Node* newNode;
				newNode -> next = nullptr;
				newNode -> deck = d;
				newNode -> last = nullptr;
				head = newNode;
			}
			size++;
		}
		
		void add(Deck d, int i)				//add:insert function for inserting a deck within the list at a given index, shifting node at index and all further nodes one element further. Must be explicitly called and cannot be called via []
		{
			//add:insert
			if(i >= 0 && i <= size)
			{
				if(i == size) {
					add(d);
				} else if(i == 0) {
					Node* newNode;
					newNode -> deck = d;
					newNode -> next = head -> next;
					head = newNode;
					size++;
				} else {
					Node* curr = head;
					for(int count = 0; count < i - 1; count++)
					{
						curr = curr -> next;
					}
					Node* newNode;
					newNode -> next = curr -> next;
					newNode -> deck = d;
					curr -> next = newNode;
					size++;
				}
			} else {
				//ErrFlow/runLog << "Index out of range";
			}
		}
		
		void remove(int i)				//delete Node at index i. shifts all values after it back towards head.
		{
			if(i >= 0 && i < size)
			{
				if(i == 0) {
					Node* temp = head;
					head = head -> next;
					delete &(temp -> deck);
					delete temp;
				} else {
					Node* curr = head;
					for(int count = 0; count < i - 1; count++)
					{
						curr = curr -> next;
					}
					Node* temp = curr -> next;
					curr -> next = temp -> next;
					delete &(temp -> deck);
					delete temp;					
				}
				size--;
			} else {
				//ErrFlow/runLog << "Index out of range";
			}
		}
		
		friend ostream& operator<<(ostream& o, const DeckArray &a)		//output operator for DeckArray
		{
			o << a.owner << endl;
			for(int i = 0; i < a.size; i++)
			{
				o << a[i] << endl;
			}
			return o;
		}
		
	private:
		Node* head;			//head pointer for linked list; corresponds to index 0
		int size;			//size of linked list, analogous to array length
		string owner;		//owner name, to be provided by client program
};


#endif
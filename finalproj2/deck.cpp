//deck.cpp
//Walker Gray

#ifndef DECK_CPP
#define DECK_CPP

#include "cardArray.cpp"
#include<cstdlib>
#include<ctime>

using namespace std;

class Deck {

friend class Player;

struct Node {
	Card* card;
	Node* next;
};

public:

	Deck()  //blank constructor for deck (mostly for declarations without initialization)
	{
		name = "";
		owner = "deckManager";
		top = nullptr;
		size = 0;
		//cout << "deck created" << endl;
	}
	int length()							//"array length" property function, returns size
	{
		return size;
	}

	Deck(string n, string o) //standard deck constructor; requires deck name from user, owner name should be the same as the player name
	{						 //		for the user creating deck and should be provided by the client program
		name = n;
		owner = o;
		top = nullptr;
		size = 0;
		//cout << "master deck init" << endl;
	}

	Deck(string n, string o, int s) //extra constructor intended to allow user to quick-make a deck by inputting a size and recieveing
	{								//		a deck of random cards of that size. May remove, undecided.
		name = n;
		owner = o;
		size = 0;
		//create random cards and push until size == s
	}

	~Deck()		//deck destructor
	{
		while(top -> next != nullptr)
		{
			Node* temp = top;
			top = top -> next;
			delete temp -> card;
			delete temp;
		}
	}

	void operator=(const Deck &d)	//deck assignment operator, copies field values of name and owner, and creates a copy of the deck by making copies of each card into a new deck, new deck will be in reverse order. pops those cards off that deck and pushes them into left side deck object
	{
		cout << "ME" << endl;
		Deck d2 = d;
		name = d2.getName();
		cout << name << endl;
		owner = d2.getOwner();
		cout << owner << endl;
		Node* curr = d2.top;
		for(int i = 0; curr != nullptr &&  i < d2.size; i++)
		{
			cout << *(curr -> card) << endl;
			push(curr -> card);
			curr = curr -> next;
		}
		cout << *this << endl;
	}

	void push(Card* c) 	//push a card object onto the deck (stack)
	{
		Node* rum = new Node;
		rum -> card = c;
		rum -> next = top;
		top = rum;
		size++;
	}

	Card* draw()		//equivilant to stack pop. draws a card off the top of the deck
	{
		Node* temp = top;
		top = top -> next;
		Card* c = temp -> card;
		delete temp;
		size--;
		return c;
	}

	bool isEmpty()	  //returns true if deck is empty
	{
		return (size <= 0);
	}

	void shuffle()	//shuffle function using special CardArray class to boost efficiency during randomization. randomizes order of cards a random number of times between 5-40
	{
		cout << "hello" << endl;
		int s = size;
		srand((unsigned int)time(NULL));
		for(int shuffles = (rand() % 35) + 5; shuffles > 0; shuffles--)
		{
			cout << "loop" << endl;
			CardArray *shor = new CardArray("player");
			CardArray arr = (*shor);
			for(int i = 0; i < s; i++)
			{
				//cout << "inner for" << endl;
				Card* temp = draw();
				//cout << "temp" << endl;
				*(arr[i]) = *temp;
				//cout << "postdraw" << endl;
			}
			int remakes = s;
			while(remakes > 0)
			{
				cout << "rem: " << remakes << endl;
				//cout << "inner while" << endl;
				srand((unsigned int)time(NULL));
				//cout << "ready" << endl;
				int element = rand() % remakes;
				//cout << "elem " << element << endl;
				//cout << "rand" << endl;
				Card* holding = arr[element];
				//cout << *holding << endl;
				cout << size << endl;
				push(holding);
				cout << "push" << endl;
				arr.remove(element);
				//cout << *this << endl;
				remakes--;
			}
			delete &arr;
		}
		cout << "is it me you're looking for" << endl;
	}

	int getSize() 	//size field getter; represents total number of cards currently in deck
	{
		return size;
	}

	string getName()	//name field getter; represents user assigned deck name
	{
		return name;
	}

	string getOwner()		//owner field getter; should be the name of the player that owns deck
	{
		return owner;
	}

	void setName(string n)	//name field setter, for when user wishes to rename deck
	{
		name = n;
	}

	void setOwner(string o)		//owner field setter..... i think i have this to support trading decks?
	{
		owner = o;
	}

	ostream& output(ostream& o) const
	{
		o << name << endl;
		o << owner << endl;
		Node* curr = top;
		for(int i = 0; curr != nullptr && i < size; i++)
		{
			o << *(curr -> card);
			cout << "size: " << size << endl;
			curr = curr -> next;
		}
		return o;
	}

	friend ostream& operator<<(ostream& o, const Deck &d)		//deck output opperator. it should be noted outputs are designed with a save file in mind, i plan on creating the loader for this because of that
	{
		return d.output(o);
	}

	void moveHead()
	{
		top = top -> next -> next;
	}

private:
	Node* top;		//top node of deck (stack)
	int size;		//size of deck (cards remaining)
	string name;	//deck name
	string owner;	//deck owner name
};


#endif

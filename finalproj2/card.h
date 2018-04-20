//card.h
//Walker Gray
//cpsc122 yugioh project
//header file for parent object of all yugioh card types

#ifndef CARD_H
#define CARD_H

#include<iostream>
#include<string>
#include<typeinfo>
#include <cassert>

using namespace std;

class Card
{
private:
	string name; 											//card name
	string description; 									//card description text
	int id; 												//card id code
public :
	Card(); 												//blank constructor for null declaration. assigns empty strings to name and description and -1 to id
	Card(string n, string d, int i); 						//standard card constructor
	~Card(); 												//card destructor
//	virtual void operator=(const Card &c);  				//card assignment operator. copies the contents of all fields from the right side card to the left side card
	string getName(); 										//getter for name field
	string getDescription(); 								//getter for description field
	int getID();											//getter for ID field
	void setName(string n); 								//setter for name field
	void setDescription(string d); 							//setter for description field
	void setID(int i); 										//setter for ID field
	virtual ostream& output(ostream& o, const Card &c) const;
	friend ostream& operator<<(ostream& o, const Card &c);  //card output operator. outputs name, description, and id on new lines
	bool operator!=(int i); 								//special override to make deck::shuffle work, i needed to be able to see if a slot in an array was empty or a card
};

#endif
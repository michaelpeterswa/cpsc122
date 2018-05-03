//player.h
//Walker Gray

#ifndef PLAYER_H
#define PLAYER_H

#include "deck.cpp"
#include "deckArray.cpp"
#include "cardArray.cpp"


class Player {


	public:

		Player();
		Player(string n);									//standard Player constructor for constructing a new Player for a new User. Requires player name
		Player(string n, DeckArray list);								//constructor for creating a Player based off of an existing list of decks. Intended for use in loading save information from file
		~Player();														//player destructor
		void operator=(const Player &p);								//player assignment operator. copies name, list of decks, and selected active deck
		string getName();												//player name field getter
		int getLifePts();
		void setLifePts(int i);
		void setName(string n);									//getter for decklist returning its DeckArray
		Deck& getDeck();												//getter for active deck. use this for duels, deck editing, etc.
		void createDeck();												//function for openning deck creation, may require client program implementation to remain inline with output format chosen
		void createDeck(Deck d);										//function for creating a deck using an existing deck. Adds deck to list as long is it meets size requirements
		friend ostream& operator<<(ostream& f, const Player &p);		//output operator override for Player objects. outputs player name and active deck name. deck list is created from file with it's owner field allowing it to be paired up with its owner, while decks when created from file use their own owner fields to find their decklist. end result of loading should be all decks for all players in same array locations as when saved, and all players active decks to have successfully persisted by using saved deck name


	private:
		string name;
		int lifePoints;												//player name field
		Deck activeDeck;							//player active deck pointer (points to value in node in linked list array)
													//DeckArray object to serve as dynamic array of decks owned by Player
};

#endif

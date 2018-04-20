//player.cpp
//Walker Gray

#include "player.h"

using namespace std;

Player::Player(){
 lifePoints = 8000;
 name = "";
}

Player::Player(string n)
{
	name = n;
	lifePoints = 8000;
	cout << "init" << endl;
}

Player::~Player()
{

}

/*void Player::operator=(const Player &p)
{
	name = p.name;
	Deck temp = *(p.activeDeck);
	activeDeck = &temp;
}
*/
string Player::getName()
{
	return name;
}
int Player::getLifePts()
{
	return lifePoints;
}
void Player::setLifePts(int i){
  lifePoints = i;
}

Deck& Player::getDeck()
{
	return activeDeck;
}

void Player::setName(string n){
	name = n;
}

void Player::createDeck()
{

}

void Player::createDeck(Deck d)
{

}
/*
ostream& operator<<(ostream& f, const Player& p)
{
	f << p.name << endl;
	f << (*(p.activeDeck)).getName() << endl;
	return f;
}
*/

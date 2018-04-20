//Walker Gray
//yuGiTest.cpp
//test all methods for all objects

#include "card.h"
#include "monster.h"
#include "player.h"

using namespace std;

void cardcpp()
{
	Card *card1 = new Card();
	Card *card2 = new Card("Test", "I am become test", 1337);
	cout << "Constructors" << endl;
	cout << "name: " << card1 -> getName() << " description: " << card1 -> getDescription() << " id: " << card1 -> getID() << endl; //name:  description:  id: 
	cout << "name: " << card2 -> getName() << " description: " << card2 -> getDescription() << " id: " << card2 -> getID() << endl; //name: Test description: I am become test id: 1337
	
	cout << endl << "operator=" << endl;
	Card card3 = *card2;
	cout << "name: " << card3.getName() << " description: " << card3.getDescription() << " id: " << card3.getID() << endl; //name: Test description: I am become test id: 1337
	card3.setName("Another Test");
	card2 -> setDescription("On second thought maybe I won't");
	cout << "name: " << card3.getName() << " description: " << card3.getDescription() << " id: " << card3.getID() << endl; //name: Another Test description: I am become test id: 1337
	cout << "name: " << card2 -> getName() << " description: " << card2 -> getDescription() << " id: " << card2 -> getID() << endl; //name: Test description: On second thought maybe I won't id: 1337
	
	cout << endl << "operator<<" << endl;
	cout << card3;	//Another Test\nI am become test\n1337\n
	
	cout << endl << "operator!=" << endl;
	cout << ((*card2) != 0) << endl; //true
	cout << ((*card1) != 0) << endl; //false
}

void monstercpp()
{
	Card *monster1 = new Monster();
	Card *monster2 = new Monster("Summmoned Skull", "Flavor Text", 1337, 2500, 1200, "Fiend", "Dark");
	cout << "Constructors" << endl;
	cout << "name: " << monster1 -> getName() << " description: " << monster1 -> getDescription() << " id: " << monster1 -> getID() << " attack: " << (static_cast<Monster*>(monster1)) -> getAttack() << " defense: " << (static_cast<Monster*>(monster1)) -> getDefense() << " type: " << (static_cast<Monster*>(monster1)) -> getType() << " attribute: " << (static_cast<Monster*>(monster1)) -> getAttribute() << endl; //name:  description:  id: -1 attack: 0 defense: 0 type:  attribute: 
	cout << "name: " << monster2 -> getName() << " description: " << monster2 -> getDescription() << " id: " << monster2 -> getID() << " attack: " << (static_cast<Monster*>(monster2)) -> getAttack() << " defense: " << (static_cast<Monster*>(monster2)) -> getDefense() << " type: " << (static_cast<Monster*>(monster2)) -> getType() << " attribute: " << (static_cast<Monster*>(monster2)) -> getAttribute() << endl; //name: Summoned Skull description: Flavor Text id: 1337 attack: 2500 defense: 1200 type: Fiend attribute: Dark
	
	cout << endl << "operator=" << endl;
	Card *monster3 = new Monster();
	Monster mons2 = *(static_cast<Monster*>(monster2));
	monster3 = &mons2;
	cout << "name: " << monster3 -> getName() << " description: " << monster3 -> getDescription() << " id: " << monster3 -> getID() << " attack: " << (static_cast<Monster*>(monster3)) -> getAttack() << " defense: " << (static_cast<Monster*>(monster3)) -> getDefense() << " type: " << (static_cast<Monster*>(monster3)) -> getType() << " attribute: " << (static_cast<Monster*>(monster3)) -> getAttribute() << endl; //name: Summoned Skull description: Flavor Text id: 1337 attack: 2500 defense: 1200 type: Fiend attribute: Dark
	monster3 -> setName("Dark Magician");
	(static_cast<Monster*>(monster2)) -> setAttack(6666);
	cout << "name: " << monster3 -> getName() << " description: " << monster3 -> getDescription() << " id: " << monster3 -> getID() << " attack: " << (static_cast<Monster*>(monster3)) -> getAttack() << " defense: " << (static_cast<Monster*>(monster3)) -> getDefense() << " type: " << (static_cast<Monster*>(monster3)) -> getType() << " attribute: " << (static_cast<Monster*>(monster3)) -> getAttribute() << endl; //name: Summoned Skull description: Flavor Text id: 1337 attack: 2500 defense: 1200 type: Fiend attribute: Dark
	cout << "name: " << monster2 -> getName() << " description: " << monster2 -> getDescription() << " id: " << monster2 -> getID() << " attack: " << (static_cast<Monster*>(monster2)) -> getAttack() << " defense: " << (static_cast<Monster*>(monster2)) -> getDefense() << " type: " << (static_cast<Monster*>(monster2)) -> getType() << " attribute: " << (static_cast<Monster*>(monster2)) -> getAttribute() << endl; //name: Summoned Skull description: Flavor Text id: 1337 attack: 2500 defense: 1200 type: Fiend attribute: Dark
	
	cout << endl << "operator<<" << endl;
	cout << (*monster3);	//Summoned Skull\nFlavor Text\n1337\n2500\n1200\nPsychic\nDark\n
}

void deckcpp()
{
	Deck *deck1 = new Deck();
	Deck *deck2 = new Deck("Fire", "wakfi");
	cout << "Constructors" << endl;
	cout << "name: " << deck1 -> getName() << " owner: " << deck1 -> getOwner() << endl;  //name:  owner: deckManager
	cout << "name: " << deck2 -> getName() << " owner: " << deck2 -> getOwner() << endl;  //name: Fire owner: wakfi
	
	Card *monster1 = new Monster("Summmoned Skull", "Flavor Text", 1337, 2500, 1200, "Fiend", "Dark");
	Card *monster2 = new Monster("Dark Magician", "Flavor Text", 1593, 2500, 2100, "Magician", "Dark");
	Card *monster3 = new Monster("Red Eyes B. Dragon", "Flavor Text", 1124, 2400, 2000, "Dragon", "Dark");
	Card *monster4 = new Monster("Blue Eyes White Dragon", "Flavor Text", 6477, 3000, 2500, "Dragon", "Light");
	Card *monster5 = new Monster("Judge Man", "Flavor Text", 5322, 2200, 1500, "Warrior", "Earth");
	Card *monster6 = new Monster("Sacred Pheonix of Nephthys", "Flavor Text", 9837, 2400, 1600, "Winged-Beast", "Fire");
	
	//Push
	deck2 -> push(monster6);
	deck2 -> push(monster5);
	deck2 -> push(monster4);
	deck2 -> push(monster3);
	deck2 -> push(monster2);
	deck2 -> push(monster1);
	
	//oper=
	
	cout << endl << "Push, operator=" << endl;
	Deck* deck3 = new Deck("Fun", "Son");
	(*deck3) = (*deck2);
	cout << (*deck2);
	cout << (*deck3) << endl;
	cout << "-3" << endl;
	//draw
	//cout << *deck3 << endl;
	cout << "-2" << endl;
	cout << *(deck2 -> draw());
	cout << "-1" << endl;
	cout << *deck3 << endl;
	cout << "0" << endl;
	cout << *(deck2 -> draw()) << endl << endl;
	
	cout << (*deck2);

	//out << *deck3 << endl;
	
	
	//shuffle
	deck3 -> shuffle();
	cout << endl << endl << "results" << endl << endl;
	cout << "1" << endl;
	cout << (*deck2);
	cout << "2" << endl;
	cout << deck3 -> getSize() << endl;
	cout << deck3;
	cout << "3" << endl;
}

void deckArraycpp()
{
	
}

void playercpp()
{
	
}

void cardArraycpp()
{
	//done
}

int main()
{
	cardcpp();
	cout << endl << endl << "**************************************************************" << endl << endl;
	monstercpp();
	cout << endl << endl << "**************************************************************" << endl << endl;
	deckcpp();
	cout << endl << endl << "**************************************************************" << endl << endl;
	deckArraycpp();
	cout << endl << endl << "**************************************************************" << endl << endl;
	playercpp();
	cout << endl << endl << "**************************************************************" << endl << endl;
	cardArraycpp();
	return 0;
}
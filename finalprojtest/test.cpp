//test.cpp
//walker gray

#include "queue.h"

using namespace std;

int main() {
	Queue *p1atk = new Queue();
	Queue *p2def = new Queue();
	Card *monster21 = new Monster("Ultimate Baseball Kid", "Flavor Text", 1156, 500, 1000, "Warrior", "Fire");
	Card *monster22 = new Monster("UFO Turtle", "Flavor Text", 9224, 1400, 1200, "Machine", "Fire");
	Card *monster23 = new Monster("Gemini Elf", "Flavor Text", 0023, 1900, 900, "Spellcaster", "Earth");
	Card *monster24 = new Monster("Time Wizard", "Flavor Text", 1985, 500, 500, "Spellcaster", "Light");
	Card *monster25 = new Monster("Lava Golem", "Flavor Text", 1661, 3000, 2500, "Fiend", "Fire");
	Card *monster26 = new Monster("Mystical Elf", "Flavor Text", 1302, 800, 2000, "Winged-Beast", "Fire");

	p1atk -> enqueue(monster21);
	p1atk -> enqueue(monster23);
	p1atk -> enqueue(monster25);

	p2def -> enqueue(monster22);
	p2def -> enqueue(monster24);
	p2def -> enqueue(monster26);

	Card *monster2 = new Monster();
	cout << "L " << p1atk -> length() << endl;
	cout << "L " << p2def -> length() << endl;
	p1atk -> dequeue(monster2);
		cout << "name: " << monster2 -> getName() << " attack: " << (static_cast<Monster*>(monster2)) -> getAttack() << " defense: " << (static_cast<Monster*>(monster2)) -> getDefense() << endl;
		/*cout << "L " << p1atk -> length() << endl;
	cout << "L " << p2def -> length() << endl;
	p2def -> dequeue(monster2);
		cout << "name: " << monster2 -> getName() << " description: " << monster2 -> getDescription() << " id: " << monster2 -> getID() << " attack: " << (static_cast<Monster*>(monster2)) -> getAttack() << " defense: " << (static_cast<Monster*>(monster2)) -> getDefense() << " type: " << (static_cast<Monster*>(monster2)) -> getType() << " attribute: " << (static_cast<Monster*>(monster2)) -> getAttribute() << endl;
		cout << "L " << p1atk -> length() << endl;
	cout << "L " << p2def -> length() << endl;
	p1atk -> dequeue(monster2);
		cout << "name: " << monster2 -> getName() << " description: " << monster2 -> getDescription() << " id: " << monster2 -> getID() << " attack: " << (static_cast<Monster*>(monster2)) -> getAttack() << " defense: " << (static_cast<Monster*>(monster2)) -> getDefense() << " type: " << (static_cast<Monster*>(monster2)) -> getType() << " attribute: " << (static_cast<Monster*>(monster2)) -> getAttribute() << endl;
		cout << "L " << p1atk -> length() << endl;
	cout << "L " << p2def -> length() << endl;
	p1atk -> dequeue(monster2);
		cout << "name: " << monster2 -> getName() << " description: " << monster2 -> getDescription() << " id: " << monster2 -> getID() << " attack: " << (static_cast<Monster*>(monster2)) -> getAttack() << " defense: " << (static_cast<Monster*>(monster2)) -> getDefense() << " type: " << (static_cast<Monster*>(monster2)) -> getType() << " attribute: " << (static_cast<Monster*>(monster2)) -> getAttribute() << endl;
		cout << "L " << p1atk -> length() << endl;
	cout << "L " << p2def -> length() << endl;
	p2def -> dequeue(monster2);
		cout << "name: " << monster2 -> getName() << " description: " << monster2 -> getDescription() << " id: " << monster2 -> getID() << " attack: " << (static_cast<Monster*>(monster2)) -> getAttack() << " defense: " << (static_cast<Monster*>(monster2)) -> getDefense() << " type: " << (static_cast<Monster*>(monster2)) -> getType() << " attribute: " << (static_cast<Monster*>(monster2)) -> getAttribute() << endl;
		cout << "L " << p1atk -> length() << endl;
	cout << "L " << p2def -> length() << endl;
	p2def -> dequeue(monster2);
		cout << "name: " << monster2 -> getName() << " description: " << monster2 -> getDescription() << " id: " << monster2 -> getID() << " attack: " << (static_cast<Monster*>(monster2)) -> getAttack() << " defense: " << (static_cast<Monster*>(monster2)) -> getDefense() << " type: " << (static_cast<Monster*>(monster2)) -> getType() << " attribute: " << (static_cast<Monster*>(monster2)) -> getAttribute() << endl;*/
	return 0;
}

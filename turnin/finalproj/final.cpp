//michael peters
//final project main file

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include "card.cpp"
#include "player.cpp"
#include "monster.cpp"

using namespace std;

struct Hand {
  Card *one;
  Card *two;
  Card *three;
  Card *four;
  Card *five;
  };

struct Node
{
	Card *value;
	Node* next = nullptr;
};

struct Queue {
	Node* front = nullptr;
	Node* rear = nullptr;
};


int coinToss(int, int);
void createPlayer(int, Player&, Player&);
void battle(int, int, Player&, Player&, Hand&, Hand&, Queue&, Queue&, Queue&, Queue&);
void menu(int, Deck, Player&, Player&, Hand&, Hand&, Hand&, Queue&, Queue&, Queue&, Queue&, int);
void add(int, Deck, Player&, Player&, Hand&, Hand&, Hand&, Queue&, Queue&, Queue&, Queue&, int, int);
void printCard(Card*);
void trade(Hand&, Hand&, Hand&);


int main(){

Player one, two;

Hand handOne, handTwo, handTemp;

Queue attackOne, defenseOne, attackTwo, defenseTwo;

Deck master("master", "game");
//----------------------------//
Card *monster1 = new Monster("Summmoned Skull", "Flavor Text", 1337, 2500, 1200, "Fiend", "Dark");
Card *monster2 = new Monster("Dark Magician", "Flavor Text", 1593, 2500, 2100, "Magician", "Dark");
Card *monster3 = new Monster("Red Eyes B. Dragon", "Flavor Text", 1124, 2400, 2000, "Dragon", "Dark");
Card *monster4 = new Monster("Blue Eyes White Dragon", "Flavor Text", 6477, 3000, 2500, "Dragon", "Light");
Card *monster5 = new Monster("Judge Man", "Flavor Text", 5322, 2200, 1500, "Warrior", "Earth");
Card *monster6 = new Monster("Sacred Pheonix of Nephthys", "Flavor Text", 9837, 2400, 1600, "Winged-Beast", "Fire");
Card *monster7 = new Monster("Ultimate Baseball Kid", "Flavor Text", 1156, 500, 1000, "Warrior", "Fire");
Card *monster8 = new Monster("UFO Turtle", "Flavor Text", 9224, 1400, 1200, "Machine", "Fire");
Card *monster9 = new Monster("Gemini Elf", "Flavor Text", 0023, 1900, 900, "Spellcaster", "Earth");
Card *monster10 = new Monster("Time Wizard", "Flavor Text", 1985, 500, 500, "Spellcaster", "Light");
Card *monster11 = new Monster("Lava Golem", "Flavor Text", 1661, 3000, 2500, "Fiend", "Fire");
Card *monster12 = new Monster("Mystical Elf", "Flavor Text", 1302, 800, 2000, "Winged-Beast", "Fire");
Card *monster13 = new Monster("Summmoned Skull", "Flavor Text", 1337, 2500, 1200, "Fiend", "Dark");
Card *monster14 = new Monster("Dark Magician", "Flavor Text", 1593, 2500, 2100, "Magician", "Dark");
Card *monster15 = new Monster("Red Eyes B. Dragon", "Flavor Text", 1124, 2400, 2000, "Dragon", "Dark");
Card *monster16 = new Monster("Blue Eyes White Dragon", "Flavor Text", 6477, 3000, 2500, "Dragon", "Light");
Card *monster17 = new Monster("Judge Man", "Flavor Text", 5322, 2200, 1500, "Warrior", "Earth");
Card *monster18 = new Monster("Sacred Pheonix of Nephthys", "Flavor Text", 9837, 2400, 1600, "Winged-Beast", "Fire");
Card *monster19 = new Monster("Ultimate Baseball Kid", "Flavor Text", 1156, 500, 1000, "Warrior", "Fire");
Card *monster20 = new Monster("UFO Turtle", "Flavor Text", 9224, 1400, 1200, "Machine", "Fire");
Card *monster21 = new Monster("Gemini Elf", "Flavor Text", 0023, 1900, 900, "Spellcaster", "Earth");
Card *monster22 = new Monster("Time Wizard", "Flavor Text", 1985, 500, 500, "Spellcaster", "Light");
Card *monster23 = new Monster("Lava Golem", "Flavor Text", 1661, 3000, 2500, "Fiend", "Fire");
Card *monster24 = new Monster("Mystical Elf", "Flavor Text", 1302, 800, 2000, "Winged-Beast", "Fire");
Card *monster25 = new Monster("Summmoned Skull", "Flavor Text", 1337, 2500, 1200, "Fiend", "Dark");
Card *monster26 = new Monster("Dark Magician", "Flavor Text", 1593, 2500, 2100, "Magician", "Dark");
Card *monster27 = new Monster("Red Eyes B. Dragon", "Flavor Text", 1124, 2400, 2000, "Dragon", "Dark");
Card *monster28 = new Monster("Blue Eyes White Dragon", "Flavor Text", 6477, 3000, 2500, "Dragon", "Light");
Card *monster29 = new Monster("Judge Man", "Flavor Text", 5322, 2200, 1500, "Warrior", "Earth");
Card *monster30 = new Monster("Sacred Pheonix of Nephthys", "Flavor Text", 9837, 2400, 1600, "Winged-Beast", "Fire");
Card *monster31 = new Monster("Ultimate Baseball Kid", "Flavor Text", 1156, 500, 1000, "Warrior", "Fire");
Card *monster32 = new Monster("UFO Turtle", "Flavor Text", 9224, 1400, 1200, "Machine", "Fire");
Card *monster33 = new Monster("Gemini Elf", "Flavor Text", 0023, 1900, 900, "Spellcaster", "Earth");
Card *monster34 = new Monster("Time Wizard", "Flavor Text", 1985, 500, 500, "Spellcaster", "Light");
Card *monster35 = new Monster("Lava Golem", "Flavor Text", 1661, 3000, 2500, "Fiend", "Fire");
Card *monster36 = new Monster("Mystical Elf", "Flavor Text", 1302, 800, 2000, "Winged-Beast", "Fire");
Card *monster37 = new Monster("Summmoned Skull", "Flavor Text", 1337, 2500, 1200, "Fiend", "Dark");
Card *monster38 = new Monster("Dark Magician", "Flavor Text", 1593, 2500, 2100, "Magician", "Dark");
Card *monster39 = new Monster("Red Eyes B. Dragon", "Flavor Text", 1124, 2400, 2000, "Dragon", "Dark");
Card *monster40 = new Monster("Blue Eyes White Dragon", "Flavor Text", 6477, 3000, 2500, "Dragon", "Light");
Card *monster41 = new Monster("Judge Man", "Flavor Text", 5322, 2200, 1500, "Warrior", "Earth");
Card *monster42 = new Monster("Sacred Pheonix of Nephthys", "Flavor Text", 9837, 2400, 1600, "Winged-Beast", "Fire");
Card *monster43 = new Monster("Ultimate Baseball Kid", "Flavor Text", 1156, 500, 1000, "Warrior", "Fire");
Card *monster44 = new Monster("UFO Turtle", "Flavor Text", 9224, 1400, 1200, "Machine", "Fire");
Card *monster45 = new Monster("Gemini Elf", "Flavor Text", 0023, 1900, 900, "Spellcaster", "Earth");
Card *monster46 = new Monster("Time Wizard", "Flavor Text", 1985, 500, 500, "Spellcaster", "Light");
Card *monster47 = new Monster("Lava Golem", "Flavor Text", 1661, 3000, 2500, "Fiend", "Fire");
Card *monster48 = new Monster("Mystical Elf", "Flavor Text", 1302, 800, 2000, "Winged-Beast", "Fire");

master.push(monster48);
master.push(monster47);
master.push(monster46);
master.push(monster45);
master.push(monster44);
master.push(monster43);
master.push(monster42);
master.push(monster41);
master.push(monster40);
master.push(monster39);
master.push(monster38);
master.push(monster37);
master.push(monster36);
master.push(monster35);
master.push(monster34);
master.push(monster33);
master.push(monster32);
master.push(monster31);
master.push(monster30);
master.push(monster29);
master.push(monster28);
master.push(monster27);
master.push(monster26);
master.push(monster25);
master.push(monster24);
master.push(monster23);
master.push(monster22);
master.push(monster21);
master.push(monster20);
master.push(monster19);
master.push(monster18);
master.push(monster17);
master.push(monster16);
master.push(monster15);
master.push(monster14);
master.push(monster13);
master.push(monster12);
master.push(monster11);
master.push(monster10);
master.push(monster9);
master.push(monster8);
master.push(monster7);
master.push(monster6);
master.push(monster5);
master.push(monster4);
master.push(monster3);
master.push(monster2);
master.push(monster1);
//----------------------------// players and coin coinToss
  unsigned int seed, playNum;
  playNum=2;
  seed = time(0);
  srand(seed);
//----------------------------//

menu(playNum, master, one, two, handOne, handTwo, handTemp, attackOne, defenseOne, attackTwo, defenseTwo, seed);

//----------------------------//

/*if(playNum > 2){
  cin.clear();
  cin.ignore();
  cout << "incorrect value" << endl;
  main();
}
*/

  return 0;
}

int coinToss(int seed,int players){
  int number;
  number = rand()%players + 1;
  return number;
}

void createPlayer(int playNum, Player &one, Player &two){

  string nameOne;
  string nameTwo;

  if(playNum > 0){
    cout << "enter name: ";
    cin >> nameOne;
  }
  if(playNum > 1){
    cout << "enter name: ";
    cin >> nameTwo;
  }
  //---------------------//
  one.setName(nameOne);
  two.setName(nameTwo);
/*
  cout << two.getLifePts() << endl;
  cout << one.getLifePts() << endl;
  */
  cout << endl;
}

void battle(int playNum, int seed, Player &one, Player &two, Hand &handOne, Hand &handTwo, Queue& attackOne, Queue& defenseOne, Queue& attackTwo, Queue& defenseTwo){
  int val = coinToss(seed, playNum);
  int counter;
  Card* choice;
  Card* choice_s;
  cout << "Player #" << val << " is up!" << endl;
  cout << endl;

  //printCard(handOne.one);

  cout << "Player one LP: " << one.getLifePts() << endl;
  cout << "Player two LP: " << two.getLifePts() << endl;
  cout << endl;
  char atk = 'n';
  char def = 'n';
  char atk_s = 'n';
  char def_s = 'n';
  if(one.getLifePts() <= 0){
    cout << "Player two wins!" << endl;
    exit(1);
  }
  if(two.getLifePts() <= 0){
    cout << "Player two wins!" << endl;
    exit(1);
  }
  if(val == 1 && one.getLifePts() > 0 && two.getLifePts() > 0){
    cout << "Player one, your cards are:" << endl;
    cout << endl;
    printCard(handOne.one);
    printCard(handOne.two);
    printCard(handOne.three);
    printCard(handOne.four);
    printCard(handOne.five);
    cout << endl;
    cout << "Which card to place in Attack? (1-5)" << endl;
    cout << "Which card to place in Defense? (1-5)" << endl;
	while(atk == def) {
		cin >> atk;
		cin >> def;
		if(atk == def) {
			cout << "Invalid Choice: Must be between 1-5 and cannot be the same" << endl;
		}
	}
	switch (atk) {
		case '1':
		{
			Node* newNode = new Node;
			newNode -> value = handOne.one;
			if(attackOne.rear == nullptr) {
				attackOne.front = newNode;
			} else {
				(attackOne.rear) -> next = newNode;
			}
			attackOne.rear = newNode;
			break;
		}
		case '2':
		{
			Node* newNode = new Node;
			newNode -> value = handOne.two;
			if(attackOne.rear == nullptr) {
				attackOne.front = newNode;
			} else {
				(attackOne.rear) -> next = newNode;
			}
			attackOne.rear = newNode;
			break;
		}
		case '3':
		{
			Node* newNode = new Node;
			newNode -> value = handOne.three;
			if(attackOne.rear == nullptr) {
				attackOne.front = newNode;
			} else {
				(attackOne.rear) -> next = newNode;
			}
			attackOne.rear = newNode;
			break;
		}
		case '4':
		{
			Node* newNode = new Node;
			newNode -> value = handOne.four;
			if(attackOne.rear == nullptr) {
				attackOne.front = newNode;
			} else {
				(attackOne.rear) -> next = newNode;
			}
			attackOne.rear = newNode;
			break;
		}
		case '5':
		{
			Node* newNode = new Node;
			newNode -> value = handOne.five;
			if(attackOne.rear == nullptr) {
				attackOne.front = newNode;
			} else {
				(attackOne.rear) -> next = newNode;
			}
			attackOne.rear = newNode;
			break;
		}
	}

	switch (def) {
		case '1':
		{
			Node* newNode = new Node;
			newNode -> value = handOne.one;
			if(defenseOne.rear == nullptr) {
				defenseOne.front = newNode;
			} else {
				(defenseOne.rear) -> next = newNode;
			}
			defenseOne.rear = newNode;
			break;
		}
		case '2':
		{
			Node* newNode = new Node;
			newNode -> value = handOne.two;
			if(defenseOne.rear == nullptr) {
				defenseOne.front = newNode;
			} else {
				(defenseOne.rear) -> next = newNode;
			}
			defenseOne.rear = newNode;
			break;
		}

		case '3':
		{
			Node* newNode = new Node;
			newNode -> value = handOne.three;
			if(defenseOne.rear == nullptr) {
				defenseOne.front = newNode;
			} else {
				(defenseOne.rear) -> next = newNode;
			}
			defenseOne.rear = newNode;
			break;
		}

		case '4':
		{
			Node* newNode = new Node;
			newNode -> value = handOne.four;
			if(defenseOne.rear == nullptr) {
				defenseOne.front = newNode;
			} else {
				(defenseOne.rear) -> next = newNode;
			}
			defenseOne.rear = newNode;
			break;
		}

		case '5':
		{
			Node* newNode = new Node;
			newNode -> value = handOne.five;
			if(defenseOne.rear == nullptr) {
				defenseOne.front = newNode;
			} else {
				(defenseOne.rear) -> next = newNode;
			}
			defenseOne.rear = newNode;
			break;
		}
	}
	//fight
  cout << "Player two, your cards are:" << endl;
  cout << endl;
  printCard(handTwo.one);
  printCard(handTwo.two);
  printCard(handTwo.three);
  printCard(handTwo.four);
  printCard(handTwo.five);
  cout << endl;
  cout << "Which card to place in Attack? (1-5)" << endl;
  cout << "Which card to place in Defense? (1-5)" << endl;
while(atk_s == def_s) {
  cin >> atk_s;
  cin >> def_s;
  if(atk_s == def_s) {
    cout << "Invalid Choice: Must be between 1-5 and cannot be the same" << endl;
  }
}
switch (atk_s) {
  case '1':
  {
    Node* newNode = new Node;
    newNode -> value = handTwo.one;
    if(attackTwo.rear == nullptr) {
      attackTwo.front = newNode;
    } else {
      (attackTwo.rear) -> next = newNode;
    }
    attackTwo.rear = newNode;
    break;
  }

  case '2':
  {
    Node* newNode = new Node;
    newNode -> value = handTwo.two;
    if(attackTwo.rear == nullptr) {
      attackTwo.front = newNode;
    } else {
      (attackTwo.rear) -> next = newNode;
    }
    attackTwo.rear = newNode;
    break;
  }

  case '3':
  {
    Node* newNode = new Node;
    newNode -> value = handTwo.three;
    if(attackTwo.rear == nullptr) {
      attackTwo.front = newNode;
    } else {
      (attackTwo.rear) -> next = newNode;
    }
    attackTwo.rear = newNode;
    break;
  }

  case '4':
  {
    Node* newNode = new Node;
    newNode -> value = handTwo.four;
    if(attackTwo.rear == nullptr) {
      attackTwo.front = newNode;
    } else {
      (attackTwo.rear) -> next = newNode;
    }
    attackTwo.rear = newNode;
    break;
  }

  case '5':
  {
    Node* newNode = new Node;
    newNode -> value = handTwo.five;
    if(attackTwo.rear == nullptr) {
      attackTwo.front = newNode;
    } else {
      (attackTwo.rear) -> next = newNode;
    }
    attackTwo.rear = newNode;
    break;
  }
}
}

switch (def_s) {
  case '1':
  {
    Node* newNode = new Node;
    newNode -> value = handTwo.one;
    if(defenseTwo.rear == nullptr) {
      defenseTwo.front = newNode;
    } else {
      (defenseTwo.rear) -> next = newNode;
    }
    defenseTwo.rear = newNode;
    break;
  }
  case '2':
  {
    Node* newNode = new Node;
    newNode -> value = handTwo.two;
    if(defenseTwo.rear == nullptr) {
      defenseTwo.front = newNode;
    } else {
      (defenseTwo.rear) -> next = newNode;
    }
    defenseTwo.rear = newNode;
    break;
  }
  case '3':
  {
    Node* newNode = new Node;
    newNode -> value = handTwo.three;
    if(defenseTwo.rear == nullptr) {
      defenseTwo.front = newNode;
    } else {
      (defenseTwo.rear) -> next = newNode;
    }
    defenseTwo.rear = newNode;
    break;
  }
  case '4':
  {
    Node* newNode = new Node;
    newNode -> value = handTwo.four;
    if(defenseTwo.rear == nullptr) {
      defenseTwo.front = newNode;
    } else {
      (defenseTwo.rear) -> next = newNode;
    }
    defenseTwo.rear = newNode;
    break;
  }
  case '5':
  {
    Node* newNode = new Node;
    newNode -> value = handTwo.five;
    if(defenseTwo.rear == nullptr) {
      defenseTwo.front = newNode;
    } else {
      (defenseTwo.rear) -> next = newNode;
    }
    defenseTwo.rear = newNode;
    break;
  }
}


/*DEQUEUE{
		Card* attack = (attackOne.rear) -> value;
		Node* temp = attackOne.rear;
		attackOne.rear = (attackOne.rear) -> next;
		delete temp;
	}*/
  if(val == 2 && one.getLifePts() > 0 && two.getLifePts() > 0){
    cout << "Player two, your cards are:" << endl;
    cout << endl;
    printCard(handTwo.one);
    printCard(handTwo.two);
    printCard(handTwo.three);
    printCard(handTwo.four);
    printCard(handTwo.five);
    cout << endl;
    cout << "Which card to place in Attack? (1-5)" << endl;
    cout << "Which card to place in Defense? (1-5)" << endl;
	while(atk == def) {
		cin >> atk;
		cin >> def;
		if(atk == def) {
			cout << "Invalid Choice: Must be between 1-5 and cannot be the same" << endl;
		}
	}
	switch (atk) {
		case '1':
		{
			Node* newNode = new Node;
			newNode -> value = handTwo.one;
			if(attackTwo.rear == nullptr) {
				attackTwo.front = newNode;
			} else {
				(attackTwo.rear) -> next = newNode;
			}
			attackTwo.rear = newNode;
			break;
		}

		case '2':
		{
			Node* newNode = new Node;
			newNode -> value = handTwo.two;
			if(attackTwo.rear == nullptr) {
				attackTwo.front = newNode;
			} else {
				(attackTwo.rear) -> next = newNode;
			}
			attackTwo.rear = newNode;
			break;
		}

		case '3':
		{
			Node* newNode = new Node;
			newNode -> value = handTwo.three;
			if(attackTwo.rear == nullptr) {
				attackTwo.front = newNode;
			} else {
				(attackTwo.rear) -> next = newNode;
			}
			attackTwo.rear = newNode;
			break;
		}

		case '4':
		{
			Node* newNode = new Node;
			newNode -> value = handTwo.four;
			if(attackTwo.rear == nullptr) {
				attackTwo.front = newNode;
			} else {
				(attackTwo.rear) -> next = newNode;
			}
			attackTwo.rear = newNode;
			break;
		}

		case '5':
		{
			Node* newNode = new Node;
			newNode -> value = handTwo.five;
			if(attackTwo.rear == nullptr) {
				attackTwo.front = newNode;
			} else {
				(attackTwo.rear) -> next = newNode;
			}
			attackTwo.rear = newNode;
			break;
		}
	}
  }

	switch (def) {
		case '1':
		{
			Node* newNode = new Node;
			newNode -> value = handTwo.one;
			if(defenseTwo.rear == nullptr) {
				defenseTwo.front = newNode;
			} else {
				(defenseTwo.rear) -> next = newNode;
			}
			defenseTwo.rear = newNode;
			break;
		}
		case '2':
		{
			Node* newNode = new Node;
			newNode -> value = handTwo.two;
			if(defenseTwo.rear == nullptr) {
				defenseTwo.front = newNode;
			} else {
				(defenseTwo.rear) -> next = newNode;
			}
			defenseTwo.rear = newNode;
			break;
		}
		case '3':
		{
			Node* newNode = new Node;
			newNode -> value = handTwo.three;
			if(defenseTwo.rear == nullptr) {
				defenseTwo.front = newNode;
			} else {
				(defenseTwo.rear) -> next = newNode;
			}
			defenseTwo.rear = newNode;
			break;
		}
		case '4':
		{
			Node* newNode = new Node;
			newNode -> value = handTwo.four;
			if(defenseTwo.rear == nullptr) {
				defenseTwo.front = newNode;
			} else {
				(defenseTwo.rear) -> next = newNode;
			}
			defenseTwo.rear = newNode;
			break;
		}
		case '5':
		{
			Node* newNode = new Node;
			newNode -> value = handTwo.five;
			if(defenseTwo.rear == nullptr) {
				defenseTwo.front = newNode;
			} else {
				(defenseTwo.rear) -> next = newNode;
			}
			defenseTwo.rear = newNode;
			break;
		}
	}
  cout << "Player one, your cards are:" << endl;
  cout << endl;
  printCard(handOne.one);
  printCard(handOne.two);
  printCard(handOne.three);
  printCard(handOne.four);
  printCard(handOne.five);
  cout << endl;
  cout << "Which card to place in Attack? (1-5)" << endl;
  cout << "Which card to place in Defense? (1-5)" << endl;
while(atk_s == def_s) {
  cin >> atk_s;
  cin >> def_s;
  if(atk_s == def_s) {
    cout << "Invalid Choice: Must be between 1-5 and cannot be the same" << endl;
  }
}
switch (atk_s) {
  case '1':
  {
    Node* newNode = new Node;
    newNode -> value = handOne.one;
    if(attackOne.rear == nullptr) {
      attackOne.front = newNode;
    } else {
      (attackOne.rear) -> next = newNode;
    }
    attackOne.rear = newNode;
    break;
  }
  case '2':
  {
    Node* newNode = new Node;
    newNode -> value = handOne.two;
    if(attackOne.rear == nullptr) {
      attackOne.front = newNode;
    } else {
      (attackOne.rear) -> next = newNode;
    }
    attackOne.rear = newNode;
    break;
  }
  case '3':
  {
    Node* newNode = new Node;
    newNode -> value = handOne.three;
    if(attackOne.rear == nullptr) {
      attackOne.front = newNode;
    } else {
      (attackOne.rear) -> next = newNode;
    }
    attackOne.rear = newNode;
    break;
  }
  case '4':
  {
    Node* newNode = new Node;
    newNode -> value = handOne.four;
    if(attackOne.rear == nullptr) {
      attackOne.front = newNode;
    } else {
      (attackOne.rear) -> next = newNode;
    }
    attackOne.rear = newNode;
    break;
  }
  case '5':
  {
    Node* newNode = new Node;
    newNode -> value = handOne.five;
    if(attackOne.rear == nullptr) {
      attackOne.front = newNode;
    } else {
      (attackOne.rear) -> next = newNode;
    }
    attackOne.rear = newNode;
    break;
  }
}

switch (def_s) {
  case '1':
  {
    Node* newNode = new Node;
    newNode -> value = handOne.one;
    if(defenseOne.rear == nullptr) {
      defenseOne.front = newNode;
    } else {
      (defenseOne.rear) -> next = newNode;
    }
    defenseOne.rear = newNode;
    break;
  }
  case '2':
  {
    Node* newNode = new Node;
    newNode -> value = handOne.two;
    if(defenseOne.rear == nullptr) {
      defenseOne.front = newNode;
    } else {
      (defenseOne.rear) -> next = newNode;
    }
    defenseOne.rear = newNode;
    break;
  }

  case '3':
  {
    Node* newNode = new Node;
    newNode -> value = handOne.three;
    if(defenseOne.rear == nullptr) {
      defenseOne.front = newNode;
    } else {
      (defenseOne.rear) -> next = newNode;
    }
    defenseOne.rear = newNode;
    break;
  }

  case '4':
  {
    Node* newNode = new Node;
    newNode -> value = handOne.four;
    if(defenseOne.rear == nullptr) {
      defenseOne.front = newNode;
    } else {
      (defenseOne.rear) -> next = newNode;
    }
    defenseOne.rear = newNode;
    break;
  }

  case '5':
  {
    Node* newNode = new Node;
    newNode -> value = handOne.five;
    if(defenseOne.rear == nullptr) {
      defenseOne.front = newNode;
    } else {
      (defenseOne.rear) -> next = newNode;
    }
    defenseOne.rear = newNode;
    break;
  }
}
cout << endl;
cout << "player one: attack or defense? (a/d)" << endl;
char state;
cin >> state;

switch(state){
  case 'a':
  {
    choice = (attackOne.rear) -> value;
    Node* temp = attackOne.rear;
    attackOne.rear = (attackOne.rear) -> next;
    delete temp;
    //cout << (static_cast<Monster*>(choice)) -> getAttack() << endl;
  }
  case 'd':
  {
    choice = (defenseOne.rear) -> value;
    Node* temp = defenseOne.rear;
    defenseOne.rear = (defenseOne.rear) -> next;
    delete temp;
  }
  default:
    break;
}
cout << endl;
cout << "player two: attack or defense? (a/d)" << endl;
char state_s;
cin >> state_s;

switch(state_s){
  case 'a':
  {
    choice_s = (attackTwo.rear) -> value;
    Node* temp = attackTwo.rear;
    attackTwo.rear = (attackTwo.rear) -> next;
    delete temp;
  }
  case 'd':
  {
    choice_s = (defenseTwo.rear) -> value;
    Node* temp = defenseTwo.rear;
    defenseTwo.rear = (defenseTwo.rear) -> next;
    delete temp;
  }
  default:
    break;
}
if(state == 'a' && state_s == 'a'){
  if((static_cast<Monster*>(choice)) -> getAttack() > (static_cast<Monster*>(choice_s)) -> getAttack()){
    two.setLifePts(two.getLifePts() - ((static_cast<Monster*>(choice)) -> getAttack() - ((static_cast<Monster*>(choice_s)) -> getAttack() )));
  }
  if((static_cast<Monster*>(choice)) -> getAttack() < (static_cast<Monster*>(choice_s)) -> getAttack()){
    one.setLifePts(one.getLifePts() - ((static_cast<Monster*>(choice_s)) -> getAttack() - ((static_cast<Monster*>(choice)) -> getAttack() )));
  }
//  (static_cast<Monster*>(attack)) -> getAttack()
}
if(state == 'd' && state_s == 'd'){
  cout << endl;
  cout << "cards discarded" << endl;
  cout << endl;
}
if(state == 'a' && state_s == 'd'){
  cout << (static_cast<Monster*>(choice)) -> getAttack() << endl;
  cout << (static_cast<Monster*>(choice_s)) -> getDefense() << endl;
  two.setLifePts(two.getLifePts() - ((static_cast<Monster*>(choice)) -> getAttack() - ((static_cast<Monster*>(choice_s)) -> getDefense() )));
}
if(state == 'd' && state_s == 'a'){
  one.setLifePts(one.getLifePts() - ((static_cast<Monster*>(choice_s)) -> getAttack() - ((static_cast<Monster*>(choice)) -> getDefense() )));
}
	//fight
battle(playNum, seed, one, two, handOne, handTwo, attackOne, defenseOne, attackTwo, defenseTwo);
}

void menu(int playNum, Deck master, Player &one, Player &two, Hand &handOne, Hand &handTwo, Hand &handTemp, Queue& attackOne, Queue& defenseOne, Queue& attackTwo, Queue& defenseTwo, int seed){

  char mode;
  int cardNum;
  cout << endl;
  cout << "---------------------------------------------------" << endl;
  cout << endl;
  cout << "Choose an output:" << endl;
  cout << "1. Create player" << endl;
  cout << "2. Add cards to specific player" << endl;
  cout << "3. Trade cards with other player" << endl;
  cout << "4. Battle! (!!must add 5 cards to both players first!!)" << endl;
  cout << "5. Exit" << endl;
  cout << endl;
  cout << "input: ";
  cin >> mode;

  cin.clear();
  cin.ignore();


  switch (mode) {
    case '1':
      cout << endl;
      createPlayer(playNum, one, two);
      menu(playNum, master, one, two, handOne, handTwo, handTemp, attackOne, defenseOne, attackTwo, defenseTwo, seed);
      break;
    case '2':
      cout << endl;
      cout << "add how many cards?" << endl;
      cin >> cardNum;
      add(playNum, master, one, two, handOne, handTwo, handTemp, attackOne, defenseOne, attackTwo, defenseTwo, seed, cardNum);
      menu(playNum, master, one, two, handOne, handTwo, handTemp, attackOne, defenseOne, attackTwo, defenseTwo, seed);
      break;
    case '3':
      cout << endl;
      trade(handOne, handTwo, handTemp);
      menu(playNum, master, one, two, handOne, handTwo, handTemp, attackOne, defenseOne, attackTwo, defenseTwo, seed);
      break;
    case '4':
      cout << endl;
      battle(playNum, seed, one, two, handOne, handTwo, attackOne, defenseOne, attackTwo, defenseTwo);
      menu(playNum, master, one, two, handOne, handTwo, handTemp, attackOne, defenseOne, attackTwo, defenseTwo, seed);
      break;
    case '5':
      exit(1);
      break;
    default:
      cout << endl;
      cout << "invalid" << endl;
      menu(playNum, master, one, two, handOne, handTwo, handTemp, attackOne, defenseOne, attackTwo, defenseTwo, seed);
      break;
  }
}
void add(int playNum, Deck master, Player &one, Player &two, Hand &handOne, Hand &handTwo, Hand &handTemp, Queue& attackOne, Queue& defenseOne, Queue& attackTwo, Queue& defenseTwo, int seed, int cardNum){
  char person;
  cout << "Which player needs to add cards?" << endl;
  cin >> person;
  cout << endl;
/*
handOne.one = one.getDeck().draw();
handOne.two = one.getDeck().draw();
handOne.three = one.getDeck().draw();
handOne.four = one.getDeck().draw();
handOne.five = one.getDeck().draw();

handTwo.one = two.getDeck().draw();
handTwo.two = two.getDeck().draw();
handTwo.three = two.getDeck().draw();
handTwo.four = two.getDeck().draw();
handTwo.five = two.getDeck().draw();
*/

  switch(person){
    case '1':
      for(int i = 0; i < cardNum; i++){
      one.getDeck().push(master.draw());
    }
      cout << one.getDeck().length()  << " cards added to player one" << endl;
      cout << endl;
      handOne.one = one.getDeck().draw();
      handOne.two = one.getDeck().draw();
      handOne.three = one.getDeck().draw();
      handOne.four = one.getDeck().draw();
      handOne.five = one.getDeck().draw();
      menu(playNum, master, one, two, handOne, handTwo, handTemp, attackOne, defenseOne, attackTwo, defenseTwo, cardNum);
      break;
    case '2':
      for(int i = 0; i < cardNum; i++){
      two.getDeck().push(master.draw());
    }
      cout << two.getDeck().length()  << " cards added to player two" << endl;
      cout << endl;
      handTwo.one = two.getDeck().draw();
      handTwo.two = two.getDeck().draw();
      handTwo.three = two.getDeck().draw();
      handTwo.four = two.getDeck().draw();
      handTwo.five = two.getDeck().draw();
      menu(playNum, master, one, two, handOne, handTwo, handTemp, attackOne, defenseOne, attackTwo, defenseTwo, cardNum);
      break;
    default:
      cout << "invalid" << endl;
      add(playNum, master, one, two, handOne, handTwo, handTemp, attackOne, defenseOne, attackTwo, defenseTwo, seed, cardNum);
      break;
    }

}

void printCard(Card *a){
  cout << a -> getName() << " | Attack Damage:" << (static_cast<Monster*>(a)) -> getAttack() << " | Defense Points:"  << (static_cast<Monster*>(a)) -> getDefense() << endl;

}
void trade(Hand &a, Hand &b, Hand &t){
  char x;
  cout << "Trading Hub!" << endl;
  cout << "Players, What card would you like to swap? (1-5)" << endl;
  cin >> x;
  cout << "Swapping Card " << x << "..." << endl;

  switch(x){
    case '1':
      t.one = a.one;
      a.one = b.one;
      b.one = t.one;
      cout << "success" << endl;
      break;
    case '2':
      t.two = a.two;
      a.two = b.two;
      b.two = t.two;
      cout << "success" << endl;
      break;
    case '3':
      t.three = a.three;
      a.three = b.three;
      b.three = t.three;
      cout << "success" << endl;
      break;
    case '4':
      t.four = a.four;
      a.four = b.four;
      b.four = t.four;
      cout << "success" << endl;
      break;
    case '5':
      t.five = a.five;
      a.five = b.five;
      b.five = t.five;
      cout << "success" << endl;
      break;
    default:
      cout << "invalid" << endl;
      break;
}

}

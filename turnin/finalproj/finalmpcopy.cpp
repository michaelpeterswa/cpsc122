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

struct Battle {

};



int coinToss(int, int);
void createPlayer(int, Player&, Player&);
void battle(int, int, Player&, Player&, Hand&, Hand&);
void menu(int, Deck, Player&, Player&, Hand&, Hand&, Hand&, int);
void add(int, Deck, Player&, Player&, Hand&, Hand&, Hand&, int, int);
void printCard(Card*);
void trade(Hand&, Hand&, Hand&);


int main(){

Player one, two;

Hand handOne, handTwo, handTemp;

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

menu(playNum, master, one, two, handOne, handTwo, handTemp, seed);

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
void battle(int playNum, int seed, Player &one, Player &two, Hand &handOne, Hand &handTwo){
  int val = coinToss(seed, playNum);
  cout << "Player #" << val << " is up!" << endl;
  cout << endl;

  //printCard(handOne.one);

  cout << "Player one LP: " << one.getLifePts() << endl;
  cout << "Player two LP: " << two.getLifePts() << endl;
  cout << endl;

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
  }
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
  }


}
void menu(int playNum, Deck master, Player &one, Player &two, Hand &handOne, Hand &handTwo, Hand &handTemp, int seed){

  char mode;
  int cardNum;
  cout << endl;
  cout << "---------------------------------------------------" << endl;
  cout << endl;
  cout << "Choose an output:" << endl;
  cout << "1. Create player" << endl;
  cout << "2. Add cards to specific player" << endl;
  cout << "3. Trade cards with other player" << endl;
  cout << "4. Battle!" << endl;
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
      menu(playNum, master, one, two, handOne, handTwo, handTemp, seed);
      break;
    case '2':
      cout << endl;
      cout << "add how many cards?" << endl;
      cin >> cardNum;
      add(playNum, master, one, two, handOne, handTwo, handTemp, seed, cardNum);
      menu(playNum, master, one, two, handOne, handTwo, handTemp, seed);
      break;
    case '3':
      cout << endl;
      trade(handOne, handTwo, handTemp);
      menu(playNum, master, one, two, handOne, handTwo, handTemp, seed);
      break;
    case '4':
      cout << endl;
      battle(playNum, seed, one, two, handOne, handTwo);
      menu(playNum, master, one, two, handOne, handTwo, handTemp, seed);
      break;
    case '5':
      exit(1);
      break;
    default:
      cout << endl;
      cout << "invalid" << endl;
      menu(playNum, master, one, two, handOne, handTwo, handTemp, seed);
      break;
  }
}
void add(int playNum, Deck master, Player &one, Player &two, Hand &handOne, Hand &handTwo, Hand &handTemp, int seed, int cardNum){
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

      menu(playNum, master, one, two, handOne, handTwo, handTemp, seed);
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
      menu(playNum, master, one, two, handOne, handTwo, handTemp, seed);
      break;
    default:
      cout << "invalid" << endl;
      add(playNum, master, one, two, handOne, handTwo, handTemp, seed, cardNum);
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

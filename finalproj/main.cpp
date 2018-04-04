#include <iostream>
#include <string>
#include "assets.h"
#include "monsters.h"
#include "players.h"
using namespace std;

int main(){
  cout << "1 - create player" << endl;
  cout << "2 - add cards to player" << endl;
  cout << "3 - trade cards with player" << endl;
  cout << "4 - battle player" << endl;
  newline(1);
  Monster first;
  Player test;
  newline(2);
  test.appendNode("michael");
  test.appendNode("nadra");
  test.displayList();
  cout << test.search("nadra");
  newline(1);

  return 0;
}

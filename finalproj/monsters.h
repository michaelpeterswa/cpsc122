#ifndef MONSTERS_H
#define MONSTERS_H

#include <iostream>
#include <string>
using namespace std;

class Monster{
  private:
    string name;
    int attackPts;
    int defensePts;
    string type;
  public:
    string getName(){
      return name;
    }
    int getAttack(){
      return attackPts;
    }
    int getDefense(){
      return defensePts;
    }
    string getType(){
      return type;
    }

    string setName(string a){
      name = a;
    }
    int setAttack(int a){
      attackPts = a;
    }
    int setDefense(int a){
      defensePts = a;
    }
    string setType(string a){
      type = a;
    }

    Monster(){
      cout << "monster initialized" << endl;

      name = "";
      attackPts = 0;
      defensePts = 0;
      type = "";
    }
};

#endif

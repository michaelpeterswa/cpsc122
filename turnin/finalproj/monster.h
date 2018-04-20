//monster.h
//Walker Gray

#ifndef MONSTERS_H
#define MONSTERS_H

#include <iostream>
#include <string>
#include "card.h"
using namespace std;

class Monster: public Card{
  private:
    int attackPts;																//monster Attack Points
    int defensePts;																//monster Defense Points
    string type;																//monster Type
	string attribute;															//monster Attribute
  public:
	Monster();																	//blank monster constructor, sets attack and defense to 0, type and attribute to empty string
	Monster(string n, string d, int i, int a, int p, string t, string r);		//standard Monster constructor: (name, description, id, attackPts, defensePts, type, attribute)
	~Monster();																	//monster destructor
//	virtual void operator=(const Card &m);									//monster assignment operator, copies values from fields of monster on right into fields of monster on left
    int getAttack();															//attack field getter
    int getDefense();															//defense field getter
    string getType();															//type field getter
	string getAttribute();														//attribute field getter
    int setAttack(int a);														//attack field setter
	int setDefense(int d);														//defense field setter
	virtual ostream& output(ostream& o, const Card &c) const;
	friend ostream& operator<<(ostream& o, const Monster &m);					//monster output operator. outputs attackPts, defensePts, type, and attribute on new lines
};

#endif
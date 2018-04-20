//monster.cpp
//Walker Gray

#include "monster.h"

using namespace std;

Monster::Monster()
:Card()
{
	attackPts = 0;
	defensePts = 0;
	type = "";
	attribute = "";
}

Monster::Monster(string n, string d, int i, int a, int p, string t, string r)
:Card(n, d, i)
{
	attackPts = a;
	defensePts = p;
	type = t;
	attribute = r;
}

Monster::~Monster()
{
	
}
/*
void Monster::operator=(const Card &c)
{
	Card *monster3 = new Monster();
	Card c2 = c;
	Monster mons2 = *(static_cast<Monster*>(&c2));
	monster3 = &mons2;
	monster3;
	
	
	
	
	cout << "its dat monster" << endl;
	Card c2 = c;
	Monster *m = static_cast<Monster*>(&c2);
	setName((*m).getName());
	setDescription((*m).getDescription());
	setID((*m).getID());
	attackPts = (*m).attackPts;
	defensePts =  (*m).defensePts;
	type = (*m).type;
	attribute = (*m).attribute;
	
}
*/
int Monster::getAttack()
{
	return attackPts;
}

int Monster::getDefense()
{
	return defensePts;
}

string Monster::getType()
{
	return type;
}

string Monster::getAttribute()
{
	return attribute;
}

int Monster::setAttack(int a)
{
	attackPts = a;
}

int Monster::setDefense(int d)
{
	defensePts = d;
}

ostream& Monster::output(ostream& o, const Card &c) const
{
	cout << "ohai" << endl;
	Card c2 = c;
	o << c2.getName() << endl;
	o << c2.getDescription() << endl;
	o << c2.getID() << endl;
	o << attackPts << endl;
	o << defensePts << endl;
	o << type << endl;
	o << attribute << endl;
	return o;
}

/*ostream& operator<<(ostream& o, const Card &c)
{
	return c.output(o, c);
}*/


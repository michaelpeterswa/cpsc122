//card.cpp
//Walker Gray

#include "card.h"

using namespace std;


Card::Card()
{
	name = "null";
	description = "null";
	id = -1;
}

Card::Card(string n, string d, int i)
{
	name = n;
	description = d;
	id = i;
}

Card::~Card()
{

}

/*void Card::operator=(const Card &c)
{
	cout << "its dat card" << endl;
	name = c.name;
	description = c.description;
	id = c.id;
} */

string Card::getName()
{
	return name;
}

string Card::getDescription()
{
	return description;
}

int Card::getID()
{
	return id;
}

void Card::setName(string n)
{
	name = n;
}

void Card::setDescription(string d)
{
	description = d;
}

void Card::setID(int i)
{
	id = i;
}

ostream& Card::output(ostream& o, const Card &c) const
{
	//cout << "haio" << endl;
	o << c.name << endl;
	o << c.description << endl;
	o << c.id << endl;
	return o;
}

ostream& operator<<(ostream& o, const Card &c)
{
	//cout << "oof" << endl;
	return c.output(o, c);
}

bool Card::operator!=(int i)
{
	if(i == 0)
	{
		if(id == -1)
		{
			return false;
		}
	}
	return true;
}


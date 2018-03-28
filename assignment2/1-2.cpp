#include <iostream>
using namespace std;

class Change
{
public:
int pennies;
int nickels;
int dimes;
int quarters;
Change()
{ pennies = nickels = dimes = quarters = 0; }
Change(int p = 100, int n = 50, d = 50, q = 25);
};
void Change::Change(int p, int n, d, q)
{
pennies = p;
nickels = n;
dimes = d;
quarters = q;
}

int main(){

return 0;
}

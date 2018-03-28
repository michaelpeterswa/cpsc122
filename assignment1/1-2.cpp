#include <iostream>
#include <string>
using namespace std;
struct Names
{
string first;
string last;
};
int main ()
{
Names customer = {"Smith", "Orley"};
cout << customer.first << endl;
cout << customer.last << endl;
return 0;
}

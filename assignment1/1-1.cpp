#include <iostream>
using namespace std;
struct ThreeVals
{
int a, b, c;
};
int main()
{
  cout << "         ______" << endl;
  cout << "    .---<__. \ \" << endl;
  cout << "    `---._  \ \ \" << endl;
  cout << "     ,----`- `.))" << endl;
  cout << "    / ,--.   )  |" << endl;
  cout << "   /_/    >     |" << endl;
  cout << "   |,\__-'      |" << endl;
  cout << "   \_           \" << endl;
  cout << "      ~~-___      )" << endl;
  cout << "            \      \" << endl;

ThreeVals vals = {1, 2, 3};

cout << vals.a << vals.b << vals.c << endl;

return 0;
}

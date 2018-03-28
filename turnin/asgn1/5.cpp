/*
Michael Peters
CPSC122
Problem 4
1/31/18
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int getInt();

struct Quarter {
  int sales;
};
struct Division {
 Quarter one;
 Quarter two;
 Quarter three;
 Quarter four;
};


int main (){

ofstream Output;
Output.open("sales.txt");

Division east;
Division west;
Division north;
Division south;

cout << "Quarter 1 sales for Division East: " << endl;
east.one.sales = getInt();
Output << "E1: " << east.one.sales << endl;
cout << "Quarter 1 sales for Division West: " << endl;
west.one.sales = getInt();
Output << "W1: " << west.one.sales << endl;
cout << "Quarter 1 sales for Division North: " << endl;
north.one.sales = getInt();
Output << "N1: " << north.one.sales << endl;
cout << "Quarter 1 sales for Division South: " << endl;
south.one.sales = getInt();
Output << "S1: " << south.one.sales << endl;
cout << "Quarter 2 sales for Division East: " << endl;
east.two.sales = getInt();
Output << "E2: " << east.two.sales << endl;
cout << "Quarter 2 sales for Division West: " << endl;
west.two.sales = getInt();
Output << "W2: " << west.two.sales << endl;
cout << "Quarter 2 sales for Division North: " << endl;
north.two.sales = getInt();
Output << "N2: " << north.two.sales << endl;
cout << "Quarter 2 sales for Division South: " << endl;
south.two.sales = getInt();
Output << "S2: " << south.two.sales << endl;
cout << "Quarter 3 sales for Division East: " << endl;
east.three.sales = getInt();
Output << "E3: " << east.three.sales << endl;
cout << "Quarter 3 sales for Division West: " << endl;
west.three.sales = getInt();
Output << "W3: " << west.three.sales << endl;
cout << "Quarter 3 sales for Division North: " << endl;
north.three.sales = getInt();
Output << "N3: " << north.three.sales << endl;
cout << "Quarter 3 sales for Division South: " << endl;
south.three.sales = getInt();
Output << "S3: " << south.three.sales << endl;
cout << "Quarter 4 sales for Division East: " << endl;
east.four.sales = getInt();
Output << "E4: " << east.four.sales << endl;
cout << "Quarter 4 sales for Division West: " << endl;
west.four.sales = getInt();
Output << "W4: " << west.four.sales << endl;
cout << "Quarter 4 sales for Division North " << endl;
north.four.sales = getInt();
Output << "N4: " << north.four.sales << endl;
cout << "Quarter 4 sales for Division South: " << endl;
south.four.sales = getInt();
Output << "S4: " << south.four.sales << endl;


Output.close();

return 0;

}

int getInt()
{
 int a;

 while(true)
 {
  if (cin >> a)
    if (a >= 0)
      break;
  cin.clear();
  cin.ignore();
  cout << "Invalid input. Integer greater than 0:" << endl;
 }
 cin.clear();
 cin.ignore();
 return a;
}

/*
Michael Peters
CPSC122
Problem 3
1/31/18
*/

#include <iostream>
#include <string>

using namespace std;

struct Car {
  string make;
  string model;
  int year;
  int price;
};


int main (){
  Car vehicles[35];

  vehicles[1].make = "Ford";
  vehicles[2].make = "Honda";
  vehicles[3].make = "Lamborghini";

  vehicles[1].model = "Taurus";
  vehicles[2].model = "Accord";
  vehicles[3].model = "Countach";

  vehicles[1].year = 1997;
  vehicles[2].year = 1992;
  vehicles[3].year = 1997;

  vehicles[1].price = 21000;
  vehicles[2].price = 11000;
  vehicles[3].price = 200000;

  for (int i = 1; i < 4; i++) {
    cout << vehicles[i].make << " " << vehicles[i].model << " " << vehicles[i].year << " $" << vehicles[i].price << endl;
  }

return 0;

}

/*
Michael Peters
CPSC122
Problem 4
1/31/18
*/

#include <iostream>
#include <string>

using namespace std;

struct MovieData {
  string title;
  string director;
  int year;
  int time;
};


int main (){
  MovieData one;
  MovieData two;

  one.title = "Movie 1";
  one.director = "Blue Scholars";
  one.year = 2000;
  one.time = 120;

  two.title = "Movie 2";
  two.director = "Macklemore";
  two.year = 2000;
  two.time = 120;

  cout << one.title << ":" << endl;
  cout << endl;
  cout << one.director << endl;
  cout << one.year << endl;
  cout << one.time << " minutes (running time)" <<endl;

  cout << endl;
  cout << endl;

  cout << two.title << ":" << endl;
  cout << endl;
  cout << two.director << endl;
  cout << two.year << endl;
  cout << two.time << " minutes (running time)" <<endl;


return 0;

}

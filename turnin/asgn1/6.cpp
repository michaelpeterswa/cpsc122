/*
Michael Peters
CPSC122
Problem 6
1/31/18
*/

#include <iostream>
#include <string>

using namespace std;

struct Player {
  string name;
  int number;
  int points;
};

void highPt(Player[]);
int totalPts(Player[]);
int getInt();


int main (){

Player athlete[12];

for (int i = 0; i < 12; i++){
  cout << "Enter Name: ";
  getline(cin, athlete[i].name);
  cout << "Enter Number: ";
  athlete[i].number = getInt();
  cout << "Enter points: ";
  athlete[i].points = getInt();
  cout << endl;

}
  cout << endl;
  int total = totalPts(athlete);

for(int i = 0; i < 12; i++){
  cout.width(20);
  cout << right << athlete[i].name << " || #" << athlete[i].number << " || " << athlete[i].points << " pts." << endl;
}
cout << endl;
cout << "total points: " << total << endl;
highPt(athlete);

return 0;

}

int totalPts(Player a[]){

int total;

total = a[0].points + a[1].points + a[2].points + a[3].points + a[4].points + a[5].points + a[6].points + a[7].points + a[8].points + a[9].points + a[10].points + a[11].points;

return total;
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

void highPt(Player a[]){

int num = 0;
int loc;

 for(int i = 0; i < 12; i++){
   if(a[i].points > num){
     num = a[i].points;
     loc = i;
   }
 }
  cout << "Most points scored by: " << a[loc].name << " (" << a[loc].points << ")" << endl;
}

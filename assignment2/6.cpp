#include <iostream>

using namespace std;

int * memAssign(int);

int main(){
int val;

cout << "how many spaces in the dynamic array?" << endl;
cin >> val;

cout << memAssign(val) << endl;


  return 0;
}

int * memAssign(int a){
  int * array;
  array = new int[a];
  return array;
  delete array;
}

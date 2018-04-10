#include <iostream>
using namespace std;

bool linearSearch(int, int[]);

int main() {

int arrayA[10] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
int input = 0;

cout << "enter your number" << endl;
cin >> input;

cout << endl;


if(linearSearch(input, arrayA)){
  cout << "you won my dude" << endl;
}
else
  cout << "you lost" << endl;

return 0;
}
bool linearSearch(int a, int array[]){
  for(int i = 0; i < 10; i++){
    if(array[i] == a)
      return true;
      }
    return false;
}

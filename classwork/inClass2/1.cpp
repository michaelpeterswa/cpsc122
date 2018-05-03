//Michael Peters

#include <iostream>

using namespace std;

int searchArrayRecursively(int[], int, int);
bool isMember(int[], int, int);
int recursivePower(int, int);

const int arraySize = 10;

int main(){
  int array[arraySize] = {1,1,2,2,2,3,4,4,5,5};
  int a, b;
  cout << "what number do you want to search for?" << endl;
  cin >> a;
  b = searchArrayRecursively(array, a, arraySize);
  cout << a << " was found " << b << " times."<< endl;
  cout << endl;
  cout << "5 to the 3rd power is " << recursivePower(5, 3) << endl;
  cout << endl;
  if(isMember(array, 5, arraySize)){
    cout << "5 was found" << endl;
  }
  else
    cout << "5 was not found in the array" << endl;
  return 0;
}

int searchArrayRecursively(int passedArray[], int num, int arraySize){

  if(arraySize >= 0){
    if(passedArray[arraySize-1] == num){
      return 1 + searchArrayRecursively(passedArray, num, arraySize-1);
    }
    else return searchArrayRecursively(passedArray, num, arraySize-1);

  }
  else
  return 0;
}

bool isMember(int passedArray[], int num, int arraySize){
  if (arraySize > -1){
    if(passedArray[arraySize-1] == num){
      return true;
    }
    else
      isMember(passedArray, num, arraySize-1);
  }
  else
    return false;
}

int recursivePower(int num, int power){
  if(power == 0){
    return 1;
  }
  else
    return num * recursivePower (num, power-1);
}

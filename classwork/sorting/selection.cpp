#include <iostream>
#include <string>
using namespace std;

void selectionSort(string array[], int);
int binarySearch(string array[], int, string);

int main() {
const int NUM_NAMES = 20;
string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim", "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee", "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth" };
// Insert your code to complete this program
cout << "pre-sort:" << endl;
cout << endl;
for(int i = 0; i < NUM_NAMES; i++){
  cout << names[i] << endl;
}
cout << endl;
cout << endl;

selectionSort(names, NUM_NAMES);
cout << "post-sort:" << endl;
cout << endl;

for(int i = 0; i < NUM_NAMES; i++){
  cout << names[i] << endl;
}
cout << endl;
cout <<"position of [Smith, Bart]: " << binarySearch(names, NUM_NAMES, "Smith, Bart") << endl;


return 0;
}

void selectionSort(string array[], int size){
  int i, minIndex;
  string minString;

  for(i=0; i < size; i++){
    minIndex = i;
    minString = array[i];
    for(int index = i + 1; index < size; index++){
      if (array[index] < minString){
        minString = array[index];
        minIndex = index;
      }
    }
    array[minIndex] = array[i];
    array[i] = minString;
  }
}

int binarySearch(string array[], int size, string value){

int first = 0;
int last = size - 1;
int middle;
int position = -1;

bool found = false;

while(!found && first <= last){
  middle = (first+last)/2;
  if (array[middle] == value){
    found = true;
    position = middle;
  }
  else if(array[middle] > value){
    last = middle - 1;
  }
  else{
    first = middle + 1;
  }
}
  return position;
}

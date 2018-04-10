#include <iostream>
using namespace std;

void printArray(int[]);
int bubbleSort(int (&array)[20]);
int selectionSort(int (&array)[20]);

int main() {

int arrayA[20] = {12,42,9,7,78,86,23,35,45,43,98,67,57,99,21,23,1,34,46,70};
int arrayB[20] = {12,42,9,7,78,86,23,35,45,43,98,67,57,99,21,23,1,34,46,70};
cout << "presort" << endl;
cout << endl;
printArray(arrayA);
cout << "BUBBLE - "<< bubbleSort(arrayA) << endl;
cout << "SELECTION - " << selectionSort(arrayB) << endl;
  return 0;
}

void printArray(int array[]){
  for(int i = 0; i < 20; i++){
    cout << array[i] << " ";
  }
  cout << endl;
}

int bubbleSort(int (&array)[20]){
int swap = 0;
int count = 0;
   for(int j = 0; j < 20; j++){
    for(int i = 0; i < 19; i++){
     if(array[i] > array[i+1]){
      swap = array[i];
      array[i] = array[i+1];
      array[i+1] = swap;
      count++;
    }
  }
}
return count;
}

int selectionSort(int (&array)[20]){
int min;
int count = 0;
int tmp;
  for(int k = 0; k < 19; k++){
    for(int a = k+1; a < 20; a++){
      if(array[a] < array[k]){
        tmp = array[k];
        array[k] = array[a];
        array[a] = tmp;
        count++;

        }
      }

  }
  return count;
}

#include <iostream>
using namespace std;

void printArray(int[]);
void bubbleSort(int (&array)[8]);
void selectionSort(int (&array)[8]);

int main() {

int arrayA[8] = {8,5,6,3,9,2,1,7};
int arrayB[8] = {8,5,6,3,9,2,1,7};
cout << "presort" << endl;
cout << endl;
printArray(arrayA);
cout << endl;

bubbleSort(arrayA);
cout << endl;

selectionSort(arrayB);
  return 0;
}

void printArray(int array[]){
  for(int i = 0; i < 8; i++){
    cout << array[i];
  }
  cout << endl;
}

void bubbleSort(int (&array)[8]){
  int swap = 0;
   for(int j = 0; j < 8; j++){
    for(int i = 0; i < 7; i++){
     if(array[i] > array[i+1]){

      swap = array[i];
      array[i] = array[i+1];
      array[i+1] = swap;
      }
    }
    cout << j+1 << " - " << "BUBBLE" << endl;
    for(int w = 0; w < 8; w++){
      cout << array[w];
    }
    cout << endl;
    cout << endl;
   }
  }

void selectionSort(int (&array)[8]){
int min;
int tmp;
  for(int k = 0; k < 7; k++){
    for(int a = k+1; a < 8; a++){
      if(array[k] > array[a]){
        tmp = array[k];
        array[k] = array[a];
        array[a] = tmp;


        }
      }
      cout << k+1 << " - " << "SELECTION" << endl;
      for(int w = 0; w < 8; w++){
        cout << array[w];
      }
      cout << endl;
      cout << endl;

  }
}

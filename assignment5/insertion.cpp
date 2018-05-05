#include <iostream>
#include <string>
using namespace std;

void insertionSort(int array[], int);

int main() {
const int NUM_AMT = 10;
int nums[NUM_AMT] = {346,234,645,476,687,798,978,105,134,153};
// Insert your code to complete this program
cout << "pre-sort:" << endl;
cout << endl;
for(int i = 0; i < NUM_AMT; i++){
  cout << nums[i] << endl;
}
cout << endl;


insertionSort(nums, NUM_AMT);
cout << "post-sort:" << endl;
cout << endl;

for(int i = 0; i < NUM_AMT; i++){
  cout << nums[i] << endl;
}
cout << endl;

return 0;
}

void insertionSort(int array[], int size){
  int j, i, temp;
  int count = 0;

  for(i=0; i < size; i++){
    j = i;

    while(j > 0 && array[j] < array[j-1]){
      count++;
      temp = array[j];
      array[j] = array[j-1];
      array[j-1] = temp;
      j--;
    }
  }
  cout << count << endl;
}

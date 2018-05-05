#include <iostream>
using namespace std;
void bucketSort(int[], int);
int main()
{
  cout << "This program uses bucket sort to output a sorted array." << endl;
  int unsortedArray[50]={97, 43, 4, 5, 53, 28, 74, 42, 78, 23, 58, 81, 21, 75, 93, 59, 80, 46, 1, 61, 12, 82, 55, 70, 18, 24, 56, 16, 22, 26, 15, 14, 79, 68, 50, 87, 27, 38, 3, 89, 10, 57, 99, 54, 25, 48, 8, 64, 35, 6};
  bucketSort(unsortedArray, 50);
  for(int i=0; i<50; i++)
    cout << unsortedArray[i] << endl;
  return 0;
}
void bucketSort(int ar[], int size)
{
  int bucketArray[100];
  for (int index=0; index < 100; index++)
  {
    bucketArray[index]=0;
  }
  for (int i=0; i<size; i++)
  {
    bucketArray[ar[i]]++;
  }
  int x=0;
  int y=0;
  while (x<size)
  {
    while (bucketArray[y]>0)
    {
      ar[x] = y+1;
      x++;
      bucketArray[y]--;
    }
    y++;
  }
}

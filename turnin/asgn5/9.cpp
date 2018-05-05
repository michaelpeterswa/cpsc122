#include <iostream>
using namespace std;
void bucket(int[], int);
int main()
{
  cout << "Bucket Sort" << endl;
  int values[50]={62, 10, 45, 49, 54, 28, 75, 88, 20, 67, 72, 77, 89, 16, 34, 18, 22, 37, 36, 30, 19, 92, 63, 15, 43, 93, 82, 56, 17, 86, 11, 40, 87, 70, 59, 1, 33, 61, 6, 55, 65, 66, 24, 44, 29, 2, 81, 84, 91, 60};
cout << endl;
cout << "pre-sort: " << endl;
    for(int i=0; i<50; i++){
      cout << values[i] << endl;
}

bucket(values, 50);
  cout << endl;
  cout << "post-sort: " << endl;
  for(int i=0; i<50; i++)
    cout << values[i] << endl;
  return 0;
}
//void bucket(int passed[], int size)
void bucket(int passed[], int size)
{
  int arr[100];
  for (int idx=0; idx < 100; idx++)
  {
    arr[idx]=0;
  }
  for (int i=0; i<size; i++)
  {
    arr[passed[i]]++;
  }
  int x=0;
  int y=0;
  while (x<size)
  {
    while (arr[y]>0)
    {
      passed[x] = y+1;
      x++;
      arr[y]--;
    }
    y++;
  }
}

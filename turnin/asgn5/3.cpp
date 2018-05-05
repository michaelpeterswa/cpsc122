#include <iostream>
using namespace std;
int mult(int, int);
int main()
{
int x, y;
cout << "Recursive Multiplication Calculator" << endl;
cout << "by Michael Peters" << endl;
cout << endl;
cout << "input first number: ";
cin >> x;
cout << "input second number: ";
cin >> y;
cout << endl;
cout << "answer = " << mult(x, y) << endl;
return 0;
}
int mult(int a, int b)
{
  if(b == 1){
    return a;
  }
  if(a == 0 || b == 0){
    return 0;
  }
  else
    return a + mult(a, b-1);
}

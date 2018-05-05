#include <iostream>
using namespace std;
int factorial(int);
int main()
{
int x;
cout << "Factorial Calculator" << endl;
cout << "by Michael Peters" << endl;
cout << endl;
cout << "input number: ";
cin >> x;
cout << endl;
cout << x << "! = " << factorial(x) << endl;
return 0;
}
int factorial(int num)
{
  int total = 1;
  for(int i = 1; i <= num; i++){
  total = total * i;
  }
  return total;
}

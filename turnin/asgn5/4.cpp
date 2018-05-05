#include <iostream>
using namespace std;
int add(int);
int main()
{
int x, y;
cout << "Recursive \"1 -> x\" Addition Calculator" << endl;
cout << "by Michael Peters" << endl;
cout << endl;
cout << "input number: ";
cin >> x;
cout << endl;
cout << "answer = " << add(x) << endl;
return 0;
}
int add(int a)
{
  if(a == 0){
    return 0;
  }
  else
    return a + add(a-1);
}

//Michael Peters
//if you are reading this... Hi

#include <iostream>
using namespace std;

int doSomething(int *x, int *y);

int main(){

int a = 2;
int b = 3;
int *bptr = &b;
int *aptr = &a;

cout << doSomething(aptr, bptr) << endl;
  return 0;
}

int doSomething(int *x, int *y){
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
  }

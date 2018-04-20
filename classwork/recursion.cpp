#include <iostream>
using namespace std;

void message(int times);

int main(){
  message(100000);
}

void message(int times){
  if(times > 0){
    cout << "this is recursive " << times << endl;
    message(times-1);
  }
}

#include <iostream>
#include <string>

using namespace std;

class Car{

private:
  int yearModel;
  string make;
  int speed;
public:
  Car(int a, string b){
    yearModel = a;
    make = b;
    speed = 0;
    }
  int getYear(){
    return yearModel;
  }
  string getMake(){
    return make;
  }
  int getSpeed(){
    return speed;
  }
  void accelerate(){
    speed += 5;
  }
  void brake(){
    while(speed >= 5){
      speed -= 5;
    }
  }
};

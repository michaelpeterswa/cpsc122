#include "car.h"

class Truck : public Car{
private:
  int bedLength;
public:
  int getBed(){
    return bedLength;
  }
  Truck(int a, int b, string c): Car(b,c){
    bedLength = a;
  }

};

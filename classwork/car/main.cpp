#include "truck.h"

int main(){

  Truck Test(7, 2016, "Toyota Tacoma TRD Pro");

  cout << Test.getYear() << " " <<Test.getMake() << endl;
  cout << "Bed length: " << Test.getBed() << "ft." << endl;

  return 0;
}

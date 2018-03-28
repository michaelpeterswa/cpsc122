#include <iostream>
#include <string>

using namespace std;



struct Product {
   string description;
   int partNum;
   float cost;
};

void display(Product array[]);

int main(){
  Product array[100];

  for(int i = 0; i < 100; i++){
    array[i].description = ' ';
    array[i].partNum = 0;
    array[i].cost = 0;
  }

  display(array);
  return 0;
}

void display(Product array[]){
  for(int i = 0; i < 100; i++){
    cout << "desc: " << array[i].description << endl;
    cout << "number: " << array[i].partNum << endl;
    cout << "cost: " << array[i].cost << endl;
    cout << endl;
  }


}

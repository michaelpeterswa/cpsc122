#include <iostream>
#include <string>

using namespace std;

class Employee{

  private:
    string name;
    int idNumber;
    string department;
    string position;
  public:
    Employee(string name, int number, string department, string position);
    Employee(string name, int number);
    Employee();

    void getID(){
      cout << "enter ID: ";
      cin >> idNumber;
    };
    void getName(){
      cout << "enter name: ";
      getline(cin, name);
    };
    string accessName(){
      return name;
    };
    void getDepartment(){
      cout << "enter department: ";
      getline(cin, department);
    };
    void getPosition(){
      cout << "enter position: ";
      getline(cin, position);
    };
    void gatherInfo(){
      getName();
      cin.clear();
      cin.ignore();
      getID();
      cin.clear();
      cin.ignore();
      getDepartment();
      cin.clear();
      cin.ignore();
      getPosition();
    };



    void printData(){
      cout << name << " " << idNumber << " " << department << " " << position << endl;
    };
  };

Employee::Employee(string name, int number, string department, string position) {
  name = name;
  idNumber = number;
  department = department;
  position = position;

}

Employee::Employee(string name, int number) {
  name = name;
  idNumber = number;
  department = "";
  position = "";

}

Employee::Employee() {
  name = "";
  idNumber = 0;
  department = "";
  position = "";

}

class ProductionWorker : public Employee {
private:
  int shift;
  double payRate;
  string name;

public:
 ProductionWorker(){

 };

 void getShift(){
   cout << "shift: ";
   cin >> shift;
 };
 void getRate(){
   cout << "enter hourly rate: ";
   cin >> payRate;
 };
 void printDataRate(){
   cout << accessName() << " " << shift << " " << payRate << endl;
 };
};
int main(){

ProductionWorker one;

one.gatherInfo();
one.getShift();
one.getRate();

one.printDataRate();




return 0;
}

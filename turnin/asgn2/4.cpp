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

int main(){

Employee one;
Employee two;
Employee three;

one.gatherInfo();
two.gatherInfo();
three.gatherInfo();
cout << endl;
one.printData();
two.printData();
three.printData();

return 0;
}

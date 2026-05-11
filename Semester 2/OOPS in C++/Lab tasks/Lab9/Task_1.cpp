#include <iostream>
using namespace std;

class Employee {   //base class 
protected:       //protected attributes 
    int EmpID;
    string EmpName;
    int hours;

public:    //public constructor and function 
    Employee(int id, string name, int h) {
        EmpID = id;
        EmpName = name;
        hours = h;
        cout << "Employee Constructor Called\n";
    }

    // Default salary for Developer
    double calculateSalary() {
        return 1800 * hours;
    }

    ~Employee() {
        cout << "Employee Destructor Called\n";
    }
};

class Developer : public Employee {  //derived class Developer inherited from Employee
private:      //private attributes 
    double salary;

public:
    Developer(int id, string name, int h) : Employee(id, name, h) {    //member initializer list for calling the base class constructor
        cout << "Developer Constructor Called\n";
        salary = calculateSalary(); // uses original version as designed for developers in base class 
    }

    void print_detail() {  //print details 
        cout << "\nDeveloper Details:\n";
        cout << "ID: " << EmpID << endl;
        cout << "Name: " << EmpName << endl;
        cout << "Hours: " << hours << endl;
        cout << "Salary: " << salary << endl;
    }

    ~Developer() {  //destructor of developer 
        cout << "Developer Destructor Called\n";
    }
};

class TeamLead : public Employee {  //derived class team lead inherited from Employee 
private:  //private attribute 
    double salary;

public:
    TeamLead(int id, string name, int h)
        : Employee(id, name, h) {  //calling the base class constructor 
        cout << "TeamLead Constructor Called\n";
        salary = calculateSalary(); // calls its own version
    }

    double calculateSalary() {   //it will not use he original base class calculatesalary 
        return 2000 * hours;
    }

    void print_detail() {   //print details of this class 
        cout << "\nTeamLead Details:\n";
        cout << "ID: " << EmpID << endl;
        cout << "Name: " << EmpName << endl;
        cout << "Hours: " << hours << endl;
        cout << "Salary: " << salary << endl;
    }

    ~TeamLead() {   //derived class constructor 
        cout << "TeamLead Destructor Called\n";
    }
};

class Manager : public Employee {
private:   //private attribute 
    double salary;

public:
    Manager(int id, string name, int h)
        : Employee(id, name, h) {   //constructor from base class 
        cout << "Manager Constructor Called\n";
        salary = calculateSalary();
    }

    double calculateSalary() {    //it will not use he original base class calculatesalary 
        return 2200 * hours;
    }

    void print_detail() {  //print details of this class 
        cout << "\nManager Details:\n";
        cout << "ID: " << EmpID << endl;
        cout << "Name: " << EmpName << endl;
        cout << "Hours: " << hours << endl;
        cout << "Salary: " << salary << endl;
    }

    ~Manager() { //derived class constructor 
        cout << "Manager Destructor Called\n";
    }
};

int main() {
    Developer d1(1, "Ali", 10);   //making object of class developer
    d1.print_detail();

    TeamLead t1(2, "Sara", 6);  //making object of class Teamlead 
    t1.print_detail();

    Manager m1(3, "Ahmed", 4);  //making object of class Manager 
    m1.print_detail();

    return 0;
}
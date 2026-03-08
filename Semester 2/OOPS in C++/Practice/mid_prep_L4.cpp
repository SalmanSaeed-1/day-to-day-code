#include<iostream>

using namespace std;

class student{
    public:
    int age;
    string name;
    student(int ag , string nam){
        age = ag;
        name = nam;
    }

    private:
    int marks;

    public:
    void setmarks(int m){
        marks = m;
    }

    int getmarks(){
        return marks;
    }
};

class employee{
    private:
    int salary;
    public:
    void setsalary(int);
    int getsalary();
};

void employee::setsalary(int sal){
    salary = sal;
}

int employee::getsalary(){
    return salary;
}

class me{
    private:
    int age;
    string name;
    public:
    me(int ag , string nam) : age(ag) , name(nam) { }

    me (const me &m2){age = m2.age ; name = m2.name;}
};

int main(){
    student s1(54 , "ali");
    s1.setmarks(99);
    cout<<"Name of student : "<<s1.name<<endl;
    cout<<"Age of student : "<<s1.age<<endl;
    cout<<"Marks of student : "<<s1.getmarks()<<endl;
    employee e1;
    e1.setsalary(100000);
    cout<<e1.getsalary();



    me m1(67 , "salman");

    me m2 = m1;



    return 0;
}
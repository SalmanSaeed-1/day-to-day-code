#include<iostream>

using namespace std;

class Student{
    int marks;

    public:
    Student(int m){
        marks = m;
    }

    bool operator==(Student s){

        if(marks == s.marks){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Student s1(80) , s2(80);

    if(s1 == s2){
        cout<<"Marks are equal ..";
    }
    else{
        cout<<"Marks are not equal ..";
    }

    return 0;
}
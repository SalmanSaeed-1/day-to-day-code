//salman saeed 2025614

#include<iostream>      //header file

using namespace std;

class Student{      //creating class
    string name;
    int rollno;        //private attributes
    float marks;

    public:     //public constructor and function
    Student(){    //default constructor
        name = "Unknown";
        rollno = 0;          //initilizing the values 
        marks = 0;
    }
    Student(string nam , int roll , float mark){     //parameterized constructor 
        name = nam;
        rollno = roll;           //setting user input values
        marks = mark; 
    }
    void display_data(){      //public function to display all the data
        cout<<"Name : "<<name<<endl;
        cout<<"Roll Number : "<<rollno<<endl;
        cout<<"Marks : "<<marks<<endl;
    }
};


int main(){
    string nam1 , nam2;       //creating variables 
    int roll1 , roll2;
    float mark1 , mark2;

    Student s1;   //craeting object which calling the default constructor 
    cout<<"Student 1 data with default constructor : "<<endl;   
    s1.display_data();    //callying the display function 

    cout<<endl<<endl;

    cout<<"Enter name 1 : ";
    getline(cin , nam1);    

    cout<<"Enter roll number 1 : ";
    cin>>roll1;

    cout<<"Enter marks 1 : ";
    cin>>mark1;

    cout<<endl;

    Student s2{nam1 , roll1 , mark1};    //creating object which calling parameterized construtor 
    cout<<"Student 2 data with parameterized constructor : "<<endl;
    s2.display_data();        //callying the display function 

    cout<<endl<<endl;

    cin.ignore();
    cout<<"Enter name 2 : ";
    getline(cin , nam2);

    cout<<"Enter roll number 2 : ";
    cin>>roll2;

    cout<<"Enter marks 2 : ";
    cin>>mark2;

    cout<<endl;

    Student s3{nam2 , roll2 , mark2};     //creating object which calling parameterized construtor 
    cout<<"Student 3 data with parameterized constructor : "<<endl;
    s3.display_data();      //callying the display function 

    cout<<endl;

    return 0;
}
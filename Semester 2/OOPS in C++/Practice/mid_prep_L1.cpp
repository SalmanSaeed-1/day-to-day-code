#include<iostream>

using namespace std;

struct date{
    int day, month , year;
};

struct student{
    int rollno;
    char name[80];
    float marks;
};

struct emp{
    char name[40];
    int salary;
    date d1;
};
union employee{ 
    int Id; 
    char Name[25]; 
    int Age; 
    long Salary; 
}; 

enum direction{north = 11 , south = 22 , east = 33  , west = 44};

enum Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main(){
    student s1;
    cout<<"Enter the roll number : ";
    cin>>s1.rollno;
    cout<<"Enter the name : ";
    cin>>s1.name;
    cout<<"Enter the marks : ";
    cin>>s1.marks;

    cout<<s1.marks<<"  "<<s1.name<<" "<<s1.rollno<<endl;

    student s2 = {450 , "salman" , 99};
    cout<<s2.marks<<"  "<<s2.name<<"  "<<s2.rollno<<endl;

    student s3 = s2;
    cout<<s3.marks<<"  "<<s3.name<<"  "<<s3.rollno<<endl;

    emp p1;
    cout<<"Enter name : ";
    cin>>p1.name;
    cout<<"Enter salary : ";
    cin>>p1.salary;
    cout<<"Enter day : ";
    cin>>p1.d1.day;
    cout<<"Enter month : ";
    cin>>p1.d1.month;
    cout<<"Enter year : ";
    cin>>p1.d1.year;

    cout<<p1.name<<"  "<<p1.salary<<" "<<p1.d1.day<<"  "<<p1.d1.month<<"  "<<p1.d1.year<<endl;

    student *sptr , s5;
    sptr = &s5;
    cout<<"Enter name : ";
    cin>>sptr->name;
    cout<<"Enter rollno : ";
    cin>>sptr->rollno;
    cout<<"Enter marks : ";
    cin>>sptr->marks;

    cout<<sptr->marks<<"  "<<sptr->name<<"  "<<sptr->rollno<<endl;

    employee E;
    cout << "\nEnter Employee Id : "; 
    cin >> E.Id; 
    cout << "\nEnter Employee Name : "; 
    cin >> E.Name; 
    cout << "\nEnter Employee Age : "; 
    cin >> E.Age;   
    cout << "\nEnter Employee Salary : "; 
    cin >> E.Salary; 

    cout << "\n\nEmployee Id : " << E.Id; 
    cout << "\nEmployee Name : " << E.Name; 
    cout << "\nEmployee Age : " << E.Age; 
    cout << "\nEmployee Salary : " << E.Salary;
    
    direction d1;
    d1 = south;
    cout<<d1;


    Day today = Wednesday;

    switch (today) {
        case Monday:
            cout << "Today is Monday";
            break;
        case Tuesday:
            cout << "Today is Tuesday";
            break;
        case Wednesday:
            cout << "Today is Wednesday";
            break;
        case Thursday:
            cout << "Today is Thursday";
            break;
        case Friday:
            cout << "Today is Friday";
            break;
        case Saturday:
            cout << "Today is Saturday";
            break;
        case Sunday:
            cout << "Today is Sunday";
            break;
        default:
            cout << "Invalid day";
    }

    date d[15];
    for(int i=0 ; i<15 ;  i++){
        cout<<"Enter the day : ";
        cin>>d[i].day;
        cout<<"Enter the month : ";
        cin>>d[i].month;
        cout<<"Enter the year : ";
        cin>>d[i].year;
    }
    for(int i=0 ; i<15 ; i++){
        cout<<d[i].day<<"  "<<d[i].month<<"   "<<d[i].year<<endl;
    }

    return 0;
}
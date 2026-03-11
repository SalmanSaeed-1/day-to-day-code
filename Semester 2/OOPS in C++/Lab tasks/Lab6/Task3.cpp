//salman saeed 2025614

#include<iostream>  //header file

using namespace std;

class Book{   //creating class
    string title;
    double *price;

    public:
    Book(string til , double pri){      //parameterized constructor 
        title = til;
        price = new double;
        *price = pri;       //pointer double price 
    }

    void display(){ //public display function 
        cout<<"Title : "<<title<<endl;
        cout<<"Price : "<<*price<<endl;
    }
    ~Book(){        //destructor 
        delete price;       //deleting the dynamic memory 
        cout<<endl;
        cout<<"Destructor has successfully deleted the dynamic memory!";
    }
};

int main(){
    string til;     //creating the variables 
    double pri;

    cout<<"Enter title of book : ";
    getline(cin , til);

    cout<<"Enter price of book : ";
    cin>>pri;

    cout<<endl;

    Book b1{til , pri};   //calling the parameterized constructor 
    b1.display();       //calling the display function 

    

    return 0;
}
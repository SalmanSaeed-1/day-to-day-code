//salman saeed 2025614

#include<iostream>  //header file

using namespace std;


class BankAccount{       //creating class
    int account_number;
    double balance;
    string owner_name;

    public:
    BankAccount(int acc_num = 2345 , double bal = 25000 , string owner = "Hassan") : account_number(acc_num) , balance(bal) , owner_name(owner) { } 
    //parameterized constructor that initializes all data members using a member initializer list

    void display_data(){        //public display function 
        cout<<"Account number : "<<account_number<<endl;
        cout<<"Balance : "<<balance<<endl;
        cout<<"Owner name : "<<owner_name<<endl;
    }
};


int main(){
    int acc_num;     //craeting variables 
    double bal;
    string owner;

    BankAccount B1;     //craeting object which calling the default constructor 
    B1.display_data();     //callying the display function 

    cout<<endl;

    cout<<"Enter account number : ";
    cin>>acc_num;

    cout<<"Enter balance : ";
    cin>>bal;

    cin.ignore();
    cout<<"Enter owner name : ";
    getline(cin , owner);

    cout<<endl;

    BankAccount B2{acc_num , bal , owner};   //creating object which calling parameterized construtor
    B2.display_data();   //callying the display function 


    return 0;
}
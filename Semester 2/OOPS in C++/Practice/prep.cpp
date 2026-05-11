#include<iostream>

using namespace std;

class wallet{
    private:
    int walletid;
    double balance;

    public:
    wallet(){
        walletid = 0;
        balance = 0;
    }
    wallet(int id , double bal){
        walletid = id;
        balance = bal;
    }
    double addmoney(double amount){
        balance += amount;
        return balance;
        cout<<"Money added successfully";
    }

    double spendmoney(double amount){
        if(balance<amount){
            cout<<"Not enough amount";
        }
        else{
            balance -= amount;
            return balance;
            cout<<"Money sepended successfully";
        }
    }

    void display(){
        cout<<"\n Wallet id : "<<walletid;
        cout<<"\n Balance : "<<balance<<endl;
    }

};

class laptop{
    private:
    string brand;
    int ram;
    double price;

    public:
    void operator>(laptop &l){
        if(price>l.price){
            cout<<"Laptop 1 price greater than 2nd one";
        }
        else{
            cout<<"2nd laptop is expensive one";
        }
    }
};


class markslist{
    private:
    int *marks;
    int count;
    int capacity;

    public:
    markslist(){
        capacity = 2;
        count = 0;
        marks = new int[capacity];
    }

    void addmark(int mark){
        if(count == capacity){
            capacity = capacity *2;
            int *temp = new int[capacity];

            for(int i=0 ; i<count ; i++){
                temp[i] = marks[i];
            }

            delete [] marks;
            marks = temp;
        }
        marks[count] = mark;
        count++;
    }
    void displaymarks(){
        for(int i=0 ; i<count ; i++){
            cout<<marks[i]<<" ";
        }
    }
    ~markslist(){
        delete[] marks;
    }
};

class shape{
    public:
    shape(){
        cout<<"Inside the shape class\n";
    }
    virtual void area(){
        cout<<"Area of shape \n";
    }
};

class Rectange :public shape{
    public:
    Rectange(): shape(){
        cout<<"Inside the rectange class\n";
    }
    void area(){
        cout<<"Area of rectangle\n";
    }
};


class circle : public shape{
    public:
    circle() : shape(){
        cout<<"Inside the circle class\n";
    }
    void area(){
        cout<<"Area of circle\n";
    }
};


int main(){

    wallet w1(123 , 50000);
    w1.addmoney(30000);
    w1.spendmoney(30000);
    w1.display();
    int choice;
    markslist m;
    while(true){
        cout<<"\n 1 - add mark \n 2 - display all marks \n 3 - exit \n";
        cout<<"Enter your choice : ";
        cin>>choice;

        if(choice == 1){
            int marks;
            cout<<"Enter marks you wanted to add : ";
            cin>>marks;
            m.addmark(marks);
        }
        else if (choice == 2){
            m.displaymarks();
        }
        else{
            break;
        }
    }

    shape *s;
    Rectange r1;
    s = &r1;
    s->area();

    circle c1;
    s = &c1;
    s->area();







    return 0;
}

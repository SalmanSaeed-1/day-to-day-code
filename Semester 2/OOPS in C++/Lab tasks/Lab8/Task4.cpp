#include<iostream>

using namespace std;

class Item{  //class
    private:
    string itemName;
    int quantity;

    public:
    Item(string i="Nill" , int q=0){    //constructor
        itemName = i;
        quantity = q;
    }

    Item operator=(Item &P){     //overloading = 
        itemName = P.itemName;
        quantity = P.quantity;
        return *this;
    }
    bool operator>=(Item &p){     //overloading >=
        if(quantity >= p.quantity){
            return true;
        }
        return false;
    }
    void print(){
        cout<<"Item name : "<<itemName<<endl;
        cout<<"Quantity : "<<quantity<<endl;
        cout<<endl;
    }
};

int main(){
    Item I1("Book" , 50);    //making objects and calling the overloading function 
    Item I2;

    I2 = I1;

    cout<<"I1 object : ";
    I1.print();

    cout<<"I2 object : ";
    I2.print();

    Item I3("pen" , 100);

    if(I1 >= I3){
        cout<<"I1 has greater quantity.";
    }
    else{
        cout<<"I3 has greater quantity.";
    }

    return 0;
}


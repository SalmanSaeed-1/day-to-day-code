#include<iostream>

using namespace std;

class BookPrice{    //class 
    private:
    int rupees;
    int paisa;

    public:
    BookPrice(int r=0 , int p=0){    //constructor 
        rupees = r;
        paisa = p;
    }
    bool operator<(BookPrice &B2){    //overloading 
        if(rupees<B2.rupees){
            return true;
        }
        if(rupees = B2.rupees && paisa<B2.paisa){
            return true;
        }
        return false;
    }
};

int main(){
    BookPrice B1(15 , 25);    //making objects and calling overloading 
    BookPrice B2(15 , 10);
    if(B1<B2){
        cout<<"Book B2 has greater price than B1.";
    }
    else{
        cout<<"Book B1 has greater price than B2.";
    }
    return 0;
}

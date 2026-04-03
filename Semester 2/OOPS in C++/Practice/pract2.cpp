#include<iostream>

using namespace std;

class Number{
    int value;

    public:
    Number(int v){
        value = v;
    }

    Number operator+(Number n){
        Number temp(0);

        temp.value = value + n.value;

        return temp;
    }
    void show(){
        cout<<"Value : "<<value;
    }
};

int main(){
    Number a(2) , b(3) , c(4);

    Number result = a + b + c;
    result.show();
}
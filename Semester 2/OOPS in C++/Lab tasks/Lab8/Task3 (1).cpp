#include<iostream>

using namespace std;

class Polynomial{    //class 
    private:
    int a , b , c;

    public:
    Polynomial(int a=0 , int b=0 , int c=0){    //constructor 
        this->a = a;
        this->b = b;
        this->c = c;
    }

    Polynomial operator+(Polynomial &P){     //overloading + to add 2 polynomials 
        Polynomial A;
        A.a = a + P.a;
        A.b = b + P.b;
        A.c = c + P.c;
        return A;
    }
    int operator()(int x){    //overloading () to calculaet the value 
        int ans = a*x*x + b*x + c;
        return ans;
    }

    void print(){
        cout<<a<<"x^2 + "<<b<<"x + "<<c<<endl;
    }
};

int main(){
    Polynomial p1(2 , 3, 4);      //making objects and calling the overloading functions 
    Polynomial p2(1 , 5 , 2);

    Polynomial result;
    result = p1 + p2;

    cout<<"Resultant polynomial : ";
    result.print();

    int value = result(3);

    cout<<"Value at x = 3 is : "<<value<<endl;

    return 0;
}
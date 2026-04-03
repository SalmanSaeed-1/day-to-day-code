#include<iostream>

using namespace std;

class Complex{
    int real , imag;

    public:
    Complex(int r , int i){
        real = r;
        imag = i;
    }

    Complex operator+(Complex c){
        Complex temp(0 , 0);
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    Complex operator-(Complex c){
        Complex temp(0, 0);
        temp.real = real - c.real;
        temp.imag = imag - c.imag;

        return temp;
    }

    void showadd(){
        cout<<real<<" + "<<imag<<"i";
    }
    void showsubtract(){
        cout<<real<<" - "<<imag<<"i";
    }

};

int main(){
    int r1  , r2 , i1 , i2;
    cout<<"Enter real number of complex number 1 : ";
    cin>>r1;
    cout<<"Enter the complex part of complex number 1 : ";
    cin>>i1;
    cout<<"Enter real number of complex number 2 : ";
    cin>>r2;
    cout<<"Enter the complex part of complex number 2 : ";
    cin>>i2;
    Complex c1(r1 , i1) , c2(r2 , i2);

    int choice;
    cout<<"Enter the opertion you want to perform : \n 1 - Add \n 2 - Subtract \n : ";
    cin>>choice;

    if(choice == 1){
        Complex c3 = c1 + c2;
        c3.showadd();
    }
    else{
        Complex c3 = c1 - c2;
        c3.showadd();
    }

    return 0;
}
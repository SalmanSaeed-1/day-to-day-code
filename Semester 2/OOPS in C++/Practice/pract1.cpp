#include<iostream>

using namespace std;

class Distance{
    int meters , centimeters;

    public:
    Distance(int m , int c){
        meters = m;
        centimeters = c;
    }

    Distance operator+(Distance d){
        Distance temp(0 , 0);

        temp.meters = meters + d.meters;
        temp.centimeters = centimeters + d.centimeters;

        if (temp.centimeters >= 100){
            temp.meters++;
            temp.centimeters = temp.centimeters - 100;
        }

        return temp;
    }

    void show(){
        cout<<meters<<"m "<<centimeters<<"cm ";
    }
};

int main(){
    Distance d1(3 , 80) , d2(2 , 40);
    Distance d3 = d1 + d2;
    d3.show();
}
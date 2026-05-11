#include<iostream>

using namespace std;

class Temperature{  //class
    private:
    int temp;

    public:
    Temperature(int t=0){  //constructor 
        temp = t;
    }
    Temperature operator-()const{   //overloading -
        return Temperature(-temp);
    }
    void print(){
        cout<<"Temperature : "<<temp<<" Degree celcius"<<endl;
    }
};

int main(){
    Temperature t1(50);    //making objects and using overloading 
    t1.print();
    Temperature t2;
    t2 = -t1;
    t2.print();
    return 0; 
}

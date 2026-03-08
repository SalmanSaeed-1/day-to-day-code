#include<iostream>
#include<iomanip>
#include<bitset>

#define limit 5
#define area(a, b) (a*b)
#define min(a ,b)((a)<(b)?a:b)
using namespace std;

void binary (int u){
    cout<<setw(5)<<u<<" : ";
    cout<<bitset<16>((int)u);
    cout<<endl;
}

int add(int a , int b){
    return a + b;
}

int subtract(int a , int b){
    return a - b;
}


int mul(int a , int b){
    return (a * b);
}


int divide(int a , int b){
    return a / b;
}



int main(){
    for(int i=0 ; i<limit ; i++){
        cout<<i<<" ";
    }
    cout<<endl;
    int a = area(5 , 4);

    cout<<a<<endl;

    cout<<min(1 ,2);
    cout<<endl;
    binary(9);

    int (*fp)(int , int);

    fp  = add;
    cout<<fp(4 , 5)<<endl;

    fp = subtract;
    cout<<fp(5 , 2)<<endl;

    fp = mul;
    cout<<fp(4 , 8)<<endl;

    fp = divide;
    cout<<fp(2 , 3)<<endl;


    return 0;
}
#include<iostream>
#include<iomanip>
#include<bitset>

using namespace std;

void binary(int u){
    cout<<setw(5)<<u<<": ";
    cout<<bitset<8>((int)u);
    cout<<"\n";
}

int main(){
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    binary(num);

    num = num | (1<<2);

    num = num & ~(1<<4);

    binary(num);



    



    return 0;
}
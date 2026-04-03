#include<iostream>

using namespace std;

enum direction {south , north , east , west};
int main(){

    direction dir;

    dir = east;

    switch(dir){
        case south:
        cout<<"Travelling in south ,,";
        break;

        case north:
        cout<<"Travelling in north ,,";
        break;

        case east:
        cout<<"Travelling in east .,";
        break;

        case west:
        cout<<"Travelling in west .. ";
        break;
    }

    return 0;
}
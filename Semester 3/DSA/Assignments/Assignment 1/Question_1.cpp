#include<iostream>

using namespace std;

struct UniverseCoordinate{
    int s_number;
    int x_position;
    int y_position;
    bool is_snake;
};

int main(){

    UniverseCoordinate point;

    point.s_number = 1;
    point.x_position = 4;
    point.y_position = 3;
    point.is_snake = true;

    cout<<"=====Snake info====="<<endl;
    cout<< "Snake Number : "<<point.s_number<<endl;
    cout<<"X Position : "<<point.x_position<<endl;
    cout<<"Y Position : "<<point.y_position<<endl;
    cout<<"Is Snake : "<<point.is_snake<<endl;

    return 0;
}
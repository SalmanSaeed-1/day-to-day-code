#include<iostream>

using namespace std;

struct student{
    int roll_number;
    string name;
    int age;
    string address;
};

void displayStudents(student arr[] , int size){
    for(int i=0 ; i<size ; i++){
        cout<<"Student "<<i<<" : "<<endl;
        cout<<"Roll number : ";
        cout<<arr[i].roll_number<<endl;
        cout<<"Name : "<<arr[i].name<<endl;
        cout<<"Age : "<<arr[i].age<<endl;
        cout<<"Address : "<<arr[i].address<<endl;
        cout<<endl;
    }
}
void age14Students(student arr[], int size){
    for(int i=0 ; i<size ; i++){
        if(arr[i].age == 14){
            cout<<"Roll number : ";
            cout<<arr[i].roll_number<<endl;
            cout<<"Name : "<<arr[i].name<<endl;
            cout<<"Age : "<<arr[i].age<<endl;
            cout<<"Address : "<<arr[i].address<<endl;
            cout<<endl; 
        }
    }
}

void evenRollStudents(student arr[], int size){
    for(int i=0 ; i<size ; i++){
        if(arr[i].roll_number % 2 == 0){
            cout<<"Roll number : ";
            cout<<arr[i].roll_number<<endl;
            cout<<"Name : "<<arr[i].name<<endl;
            cout<<"Age : "<<arr[i].age<<endl;
            cout<<"Address : "<<arr[i].address<<endl;
            cout<<endl;    
        }
    }
}

void searchStudent(student* arr, int size, int roll){
    for(int i=0 ; i<size ; i++){
        if(arr->roll_number = roll){
            cout<<"Roll number : ";
            cout<<arr[i].roll_number<<endl;
            cout<<"Name : "<<arr[i].name<<endl;
            cout<<"Age : "<<arr[i].age<<endl;
            cout<<"Address : "<<arr[i].address<<endl;
            cout<<endl; 
        }
    }
}

void updateAge(student* s, int age){
    s->age = age;
}
int main(){

    int rows = 4;
    int cols = 5;

    int** arr = new int*[rows];

    for(int i=0 ; i<rows ; i++){
        arr[i] = new int[cols];
    }


    for(int i=0 ; i<rows ; i++){
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}
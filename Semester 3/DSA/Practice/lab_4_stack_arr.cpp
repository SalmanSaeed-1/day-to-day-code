//  push – Adds or pushes an element into the stack. 
// ➢ pop – Removes or pops an element out of the stack. 
// ➢ peek – Gets the top element of the stack but doesn’t remove it. 
// ➢ isFull – Tests if the stack is full. 
// ➢ isEmpty –

#include<iostream>

using namespace std;

#define size 5


class stack{
    int top;

    public:
    stack(){
        top = -1;
    }

    int arr[size];

    bool isempty(){
    return top == -1;
    }

    bool isfull(){
        return top == 4;
    }

    void push(int data){
        if(isfull()){
            cout<<"stack is already full!"<<endl;
            return;
        }
        top++;
        arr[top] = data;
    }   

    void pop(){
        if(isempty()){
            cout<<"Stack is empty!"<<endl;
            return;
        }

        top--;
    }

    void peek(){
        if(isempty()){
            cout<<"Stack is empty";
        }
        cout <<"Element at the top is : "<<top[arr]<<endl;
    }


};




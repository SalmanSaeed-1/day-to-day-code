#include<iostream>

using namespace std;

#define size 5

class queue{
    int front , rear;
    int arr[size];

    public:
    queue(){
        front = -1;
        rear = -1;
    }

    bool isfull(){
        return rear == size -1;
    }

    bool isempty(){
        return front == -1 || front > rear;
    }

    void push(int data){
        if(isfull()){
            cout<<"Queue is already empty!";
            return;
        }
        if(front == -1){
            front = 0;
        }
        rear++;
        arr[rear] = data;
    }

    void pop(){
        if(isempty()){
            cout<<"queue is already empty!"<<endl;
            return;
        }
        front++;
        if(front>rear){
            front = -1;
            rear = -1;
        }
    }

    void peek(){
        if(isempty()){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        cout<<"Peek element is "<<arr[front]<<endl;
    }

};
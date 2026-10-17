#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
    Node* top;

    public:
    Stack(){
        top = NULL;
    }

    bool isempty(){
        return top == NULL;
    }

    void push(int data){
        Node* newnode = new Node;
        newnode->data = data;
        
        newnode->next = top;
        top = newnode;

    }

    void pop(){
        if(isempty()){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void peek(){
        if(isempty()){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        cout<<"Element at the top is : "<<top->data<<endl;
    }
    
};

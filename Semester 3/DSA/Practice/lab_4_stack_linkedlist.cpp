#include<iostream>
#include<string>

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



    bool valid_parenthesis(const string& s){
        bool valid = true;
        int count = 0;

        for(size_t i = 0 ; i<s.length() ; i++){
            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '['){
                push(ch);
                count++;
            }
            else if(ch == ')' || ch == '}' || ch == ']'){
                if(count = 0){
                    valid = false;
                    break;
                }
                char opening = top->data;
                if(ch == ')' && opening!='('||
                   ch == '}' && opening!='{'||
                   ch == ']' && opening!='['
                ){
                    valid = false;
                    break;
                }
                pop();
                count--;
            }
        }
        if(count!=0){
            valid = false;
        }
        while(count>0){
            pop();
            count--;
        }
        return valid;
    }

    void peek(){
        if(isempty()){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        cout<<"Element at the top is : "<<top->data<<endl;
    }

};

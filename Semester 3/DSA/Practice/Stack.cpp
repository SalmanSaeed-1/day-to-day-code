#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class stack{
    Node* topnode;

    public:
    stack(){
        topnode = nullptr;
    }

    void push(int val){
        Node* newnode = new Node;
        newnode->data = val;
        newnode->next = nullptr;
        newnode->next = topnode;
        topnode = newnode;

    }

    void pop(){
        if(topnode == NULL){
            cout<<"Stack underflow!!"<<endl;
            return;
        }
        Node* temp = topnode;
        topnode = topnode->next;
        temp->next = nullptr;
        delete temp;
    }

    int top(){
        if(topnode == NULL){
            cout<<"stack is empty!!"<<endl;
            return -1;
        }
        return topnode->data;
    }

    bool isempty(){
        if(topnode == NULL){
            return true;
        }else{
            return false;
        }   
    }

    void show(){
        if(topnode == NULL){
            cout<<"stack is empty!!"<<endl;
            return;
        }
        Node* curr = topnode;
        while(curr != nullptr){
            cout<<curr->data<<endl;
            curr = curr->next;
        }
    }

};

int main(){
    stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.show(); // Output: 30 -> 20 -> 10 -> NULL

    cout << "Top element is: " << st.top() << endl; // Output: 30

    st.pop();
    cout << "After popping one element:" << endl;
    st.show(); // Output: 20 -> 10 -> NULL



    return 0;
}
#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class queue{
    Node* head;
    Node* tail;

    public:
    queue(){
        head = tail = NULL;
    }

    void enqueue(int data){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = NULL;

        if(head == NULL){
            head = tail = newnode;
            return;
        }

        tail->next = newnode;
        tail = newnode;

    }

    void dequeue(){
        if(head == NULL){
            cout<<"Linked list is empty!";
            return;
        }
        Node* temp = head;
        
        head = head->next; 

        if(head == NULL){
            tail = NULL;
        }
        
        delete temp;

    }
};
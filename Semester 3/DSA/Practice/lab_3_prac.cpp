#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class doubly_linked_list{
    private:
    Node* head;
    Node* tail;

    public:
    doubly_linked_list(){
        head = tail = NULL;
    }

    void add_at_head(int data){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL){
            head = tail = newnode;
            return;
        }

        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }

    void add_at_tail(int data){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;

        if(head == NULL){
            head = tail = newnode;
            return;
        }

        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }

    void delete_at_head(){
        if(head == NULL){
            cout<<"Linked list is empty!";
            return;
        }
        Node* temp = head;
        head = head->next;
    
        if(head != NULL){
            head->prev = NULL;
        } else {
            tail = NULL; // The list is now completely empty
        }
        delete temp;
    }

    void delete_at_tail(){
        if(head == NULL){
            cout<<"Linked list is empty!";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
    
        if(tail != NULL){
            tail->next = NULL;
        } else {
            head = NULL; // The list is now completely empty
        }
        delete temp;
    }

    void add_at_specific_position(int data , int pos){
        if(pos<=0){
            cout<<"Invalid position!";
            return;
        }
        if(pos == 1){
            add_at_head(data);
            return;
        }

        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        
        int count = 1;

        Node* current = head;

        while(current!=NULL && count < pos - 1){
            current = current->next;
            count++;
        }

        if(current == NULL){
            cout<<"position out of range!";
            return;
        }

        newnode->next = current->next;
        newnode->prev = current;
        if(current->next != NULL){
            current->next->prev = newnode;
        }
        else{
            tail = newnode;
        }
        current->next = newnode;
    }

    void delete_at_specific_position(int pos){
        if(pos<=0){
            cout<<"Invalid position!!";
            return;
        }

        if(pos==1){
            delete_at_head();
            return;
        }

        Node* current = head;

        int count = 1;

        while(current!=NULL && count < pos){
            current = current->next;
            count++;
        }

        if(current == NULL){
            cout<<"Position out of range!";
            return;

        }

        if(current->prev != NULL){
            current->prev->next = current->next;
        }
        if(current->next != NULL){
            current->next->prev = current->prev;
        }
        else{
            tail = current->prev;
        }
        delete current;
    }



    void display_list_forward(){
        Node* current = head;
        while(current != NULL){
            cout<<current->data<<" <--> ";
            current = current->next;
        }
        cout<<"NULL";
    }

    void display_list_backward(){
        Node* current = tail;
        while(current != NULL){
            cout<<current->data<<" <--> ";
            current = current->prev;
        }
        cout<<"NULL";
    }
};

int main() {
    doubly_linked_list list;

    list.add_at_head(10);
    list.add_at_head(20);
    list.add_at_tail(30);
    list.add_at_tail(40);

    cout << "List forward: ";
    list.display_list_forward();   // 20 <-> 10 <-> 30 <-> 40 -> NULL
    cout<<endl<<endl;

    cout << "List backward: ";
    list.display_list_backward();  // 40 <-> 30 <-> 10 <-> 20 -> NULL
    cout<<endl<<endl;


    list.add_at_specific_position(25, 3);
    cout << "After inserting 25 at pos 3: ";
    list.display_list_forward();   // 20 <-> 10 <-> 25 <-> 30 <-> 40 -> NULL
    cout<<endl<<endl;


    list.delete_at_head();
    cout << "After deleting head: ";
    list.display_list_forward();   // 10 <-> 25 <-> 30 <-> 40 -> NULL
    cout<<endl<<endl;


    list.delete_at_tail();
    cout << "After deleting tail: ";
    list.display_list_forward();   // 10 <-> 25 <-> 30 -> NULL
    cout<<endl<<endl;


    list.delete_at_specific_position(2);
    cout << "After deleting node at pos 2: ";
    list.display_list_forward();   // 10 <-> 30 -> NULL
    cout<<endl<<endl;


    return 0;
}


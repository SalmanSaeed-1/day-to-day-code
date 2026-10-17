#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class Linked_list{
    private:
    Node* head;
    Node* tail;

    public:
    Linked_list(){
        head = tail = NULL;
    }

    void add_at_head(int data){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = NULL;
        if(tail == NULL){
            head = tail = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }

    void add_at_tail(int data){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = NULL;
        if(tail == NULL){
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
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

        int count = 1;

        Node* current = head;
        while(current!=NULL &&  count < pos -1){
            current = current->next;
            count++;
        }

        if(current == NULL){
            cout<<"Position out of range!";
            delete newnode;
            return;
        }

        newnode->next = current->next;
        current->next = newnode;

        if(newnode->next == NULL){
            tail = newnode;
        }
    }

    void delete_at_head(){
        if(head == NULL){
            cout<<"List is empty";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;

        if(head == NULL){
            tail = NULL;
        }
    }

    void delete_at_tail(){
        if(head == NULL){
            cout<<"List is empty!";
            return;
        }

        if(head->next == NULL){
            delete head;
            head = tail = NULL;
            return;
        }

        Node* current = head;
        while(current->next != tail){
            current = current->next;
        }
        Node* temp = tail;
        tail = current;
        tail->next = NULL;
        delete temp;
    }

    void delete_at_specific_position(int pos){
        if(pos<=0){
            cout<<"Invlaid position!";
            return;
        }

        if(pos == 1){
            delete_at_head();
            return;
        }

        Node* current = head;
        int count = 1;

        while(current != NULL && count < pos -1 ){
            current = current->next;
            count++;
        }

        if(current == NULL || current->next == NULL){
            cout<<"Position out of range!";
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;

        if(temp == tail){
            tail = current;
        }
        
        delete temp;
    }


    void display(){
        Node* current = head;
        while(current != NULL){
            cout<<current->data<<" ->";
            current = current->next;
        }
        cout<<"NULL";
    }
};


int main(){
    Linked_list list;

    list.add_at_head(10);
    list.add_at_head(20);
    list.add_at_head(30);
    list.add_at_tail(40);
    list.add_at_tail(50);

    cout << "List after insertions: ";
    list.display();   // Expected: 30 -> 20 -> 10 -> 40 -> 50 -> NULL
    cout<<endl<<endl;

    list.add_at_specific_position(25, 3);
    cout << "After inserting 25 at position 3: ";
    list.display();   // Expected: 30 -> 20 -> 25 -> 10 -> 40 -> 50 -> NULL
    cout<<endl<<endl;


    list.delete_at_head();
    cout << "After deleting head: ";
    list.display();   // Expected: 20 -> 25 -> 10 -> 40 -> 50 -> NULL
    cout<<endl<<endl;

    list.delete_at_tail();
    cout << "After deleting tail: ";
    list.display();   // Expected: 20 -> 25 -> 10 -> 40 -> NULL
    cout<<endl<<endl;


    list.delete_at_specific_position(2);
    cout << "After deleting node at position 2: ";
    list.display();   // Expected: 20 -> 10 -> 40 -> NULL
    cout<<endl<<endl;
    
    return 0;
}
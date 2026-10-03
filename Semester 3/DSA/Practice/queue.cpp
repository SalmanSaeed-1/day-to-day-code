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
        head = tail = nullptr;
    }

    void push(int val){
        Node* newnode = new Node;
        newnode->data = val;
        newnode->next = nullptr;
        if(head == NULL){
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void pop(){
        if(head == nullptr){
            cout<<"Stack is empty!!"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    int front(){
        if(head == nullptr){
            cout<<"Stack is empty!!"<<endl;
            return -1;
        }
        return head->data;
    }

    bool isempty(){
        return head == nullptr;
    }

    void show(){
        if(head == nullptr){
            cout<<"Stack is empty!!"<<endl;
            return;
        }
        Node* curr = head;
        while(curr != NULL){
            cout<<curr->data<<"-->";
            curr = curr->next;
        } 
        cout<<endl;
    }
};




int main() {
    queue q; // Assuming your class is named Queue

    cout << "--- TEST 2: UNDERFLOW ---" << endl;
    q.pop(); // Should print error
    cout << "Front is: " << q.front() << endl; // Should print error and -1

    cout << "\n--- TEST 1: HAPPY PATH ---" << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.show(); // Expected: 10 20 30
    cout << "Front is: " << q.front() << endl; // Expected: 10
    q.pop(); 
    q.show(); // Expected: 20 30

    cout << "\n--- TEST 3: SINGLE ELEMENT TRAP ---" << endl;
    queue q2;
    q2.push(99);
    cout << "Is q2 empty? " << (q2.isempty() ? "Yes" : "No") << endl; // Expected: Yes

    cout << "\n--- TEST 4: ALTERNATING ---" << endl;
    queue q3;
    q3.push(1); q3.pop();
    q3.push(2); q3.pop();
    q3.push(3); q3.pop();
    cout << "Is q3 empty? " << (q3.isempty() ? "Yes" : "No") << endl; // Expected: Yes

    return 0;
}

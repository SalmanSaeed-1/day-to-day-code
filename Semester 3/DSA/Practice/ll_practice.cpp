#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class List{

    Node* head;
    Node* tail;

    public:
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void show(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }

    void push_back(int val){
        Node* newNode = new Node;
        newNode->next = NULL;
        newNode->data = val;
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        Node* temp = head;
        if(head == NULL){
            cout<<"List is empty";
        }else{
            head = head->next;
            tail->next = nullptr;
            delete temp;
        }
    }

    void pop_back(){
        Node* temp = head;
        if(head == NULL){
            cout<<"List is empty";
        }else{
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }

    void push_specificpos(int val , int pos){
        if(pos<0){
            cout<<"Invalid position";
            return;
        }
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        Node* temp = head;
        for(int i=0 ; i< pos - 1 ; i++){
            if(temp == NULL){
                cout<<"Invalid position";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void serach(int val){
        Node* temp = head;
        while(temp != NULL){
            if((temp->data) == val){
                cout<<"Value founded in Linked list";
                return;
            }
            temp = temp->next;
        }
        cout<<"Value not founded"<<endl;
    }

    void reverse_link(){
        Node* pre = NULL;
        Node*  curr = head;
        Node* next = NULL;
        tail = head;
        while(curr != NULL){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        head = pre;
    }

    int middle(){
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    bool detect_cycle(){
        Node* slow = head;
        Node* fast = head;
        while(fast != NULl && fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }

    int start_cycle(){
        Node* slow = head;
        Node* fast = head;
        bool iscycle = false;
        while(fast!= NULL && fast->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                iscycle = true;
                break;
            }
        }
        if(!iscycle){
            return -1;
        }

        slow = head;
        while(fast != head){
            fast = fast->next;
            slow = slow->next;
        }

        return slow->data;
    }

    
    void remove_cycle(){
        Node* slow = head;
        Node* fast = head;
        bool iscycle = false;
        while(fast!= NULL && fast->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                iscycle = true;
                break;
            }
        }
        if(!iscycle){
            return -1;
        }

        slow = head;
        Node* prev = NULL;
        while(fast != head){
            prev = fast;
            fast = fast->next;
            slow = slow->next;
        }

        prev->next = NULL;
    }
};



int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(10);
    ll.push_back(9);
    ll.push_back(8);
    ll.push_back(7);

    ll.show();
    cout<<endl;

    ll.pop_front();
    ll.pop_back();

    ll.show();

    ll.push_specificpos(19 , 1);

    cout<<endl;

    ll.show();

    ll.push_specificpos(20 , 5);

    cout<<endl;

    ll.show();
    cout<<endl;

    ll.serach(9);
    cout<<endl;

    ll.serach(20);
    cout<<endl;

    ll.serach(100);

    cout<<endl;
    ll.reverse_link();
    ll.show();

    cout<<endl;

    int mid = ll.middle();
    cout<<mid;
    return 0;
}
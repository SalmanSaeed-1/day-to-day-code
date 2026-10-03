#include<iostream>

using namespace std;

#define max 5
int front = -1;
int rear = -1;
int arr[max];

class queue{
    public:
    void enqueue(int val){
        if(rear == max - 1){
            cout<<"overflow"<<endl;
            return;
        }

        if(front == -1){
            front = 0;
        }

        rear++;
        arr[rear] = val;
    }

    void dequeue(){
        if(front == -1 || front>rear){
            cout<<"queue is empty";
            return;
        }

        front++;

        if(front>rear){
            front = -1;
            rear = -1;
        }
        
    }

    int get_front(){
        if(front == -1 || front>rear){
            cout<<"queue is empty";
            return -1;
        }
        return arr[front];

    }

    bool isempty(){
        return (front == -1 || front > rear);
    }

void show() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue (Front to Rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};

int main(){
    queue q;

    // 1. Happy Path Test
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.show(); // Expected: 10 20 30

    cout << "Front is: " << q.get_front() << endl; // Expected: 10

    q.dequeue();
    cout << "After 1 dequeue:" << endl;
    q.show(); // Expected: 20 30

    // 2. Overflow Test
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // This should trigger Overflow because MAX is 5
    
    q.show(); // Expected: 20 30 40 50


    return 0;
}
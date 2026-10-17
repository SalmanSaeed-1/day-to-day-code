#include<iostream>

using namespace std;

#define size 5

class CircularQueue {
private:
    int front;
    int rear;
    int arr[size];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isempty() {
        return front == -1;
    }

    bool isfull() {
        // The queue is full if the next position of rear wraps around to meet front
        return (rear + 1) % size == front;
    }

    void enqueue(int data) {
        if(isfull()) {
            cout << "Queue is already full! Cannot enqueue " << data << endl;
            return;
        }

        // If inserting the very first element
        if(front == -1) {
            front = 0;
            rear = 0;
        } 
        else {
            // Wrap rear around to 0 if it reaches the end of the array
            rear = (rear + 1) % size;
        }
        
        arr[rear] = data;
        cout << "Enqueued: " << data << endl;
    }

    void dequeue() {
        if(isempty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        // If the queue only had one element, reset it to completely empty
        if(front == rear) {
            front = -1;
            rear = -1;
        } 
        else {
            // Wrap front around to 0 if it reaches the end of the array
            front = (front + 1) % size;
        }
    }

    void peek() {
        if(isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }
};

int main() {
    CircularQueue cq;

    cout << "--- Enqueue Elements ---" << endl;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cout << "\n--- Test Overflow ---" << endl;
    cq.enqueue(60); // Should print "Queue is already full!"

    cout << "\n--- Dequeue Elements ---" << endl;
    cq.dequeue(); // Removes 10
    cq.dequeue(); // Removes 20

    cout << "\n--- Test Circular Behavior ---" << endl;
    // In a normal linear queue, these would fail because rear was at the end.
    // In a circular queue, these will wrap around to the front of the array!
    cq.enqueue(60); 
    cq.enqueue(70);

    cq.peek(); // Front should now be 30

    return 0;
}
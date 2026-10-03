#include <iostream>
using namespace std;

#define MAX 5 // Small size so we can easily test overflow

class Queue {
    int arr[MAX];
    int frontIndex;
    int rearIndex;

public:
    // Constructor initializes an empty queue
    Queue() {
        frontIndex = -1;
        rearIndex = -1;
    }

    // ENQUEUE: Add an element to the back (rear)
    void enqueue(int val) {
        // 1. Check for Overflow
        if (rearIndex == MAX - 1) {
            cout << "Queue Overflow! Cannot enqueue " << val << endl;
            return;
        }
        
        // 2. If it's the very first element, we must move frontIndex to 0
        if (frontIndex == -1) {
            frontIndex = 0;
        }
        
        // 3. Move rear forward and insert the value
        rearIndex++;
        arr[rearIndex] = val;
    }

    // DEQUEUE: Remove an element from the front
    void dequeue() {
        // 1. Check for Underflow
        if (frontIndex == -1 || frontIndex > rearIndex) {
            cout << "Queue Underflow! Queue is already empty." << endl;
            return;
        }
        
        // 2. Move frontIndex forward to "delete" the element
        frontIndex++;
        
        // 3. OPTIMIZATION: If the queue is now completely empty, reset indices 
        // back to -1. This helps prevent the array from filling up with "dead space".
        if (frontIndex > rearIndex) {
            frontIndex = -1;
            rearIndex = -1;
        }
    }

    // FRONT: View the element at the front of the line
    int front() {
        if (frontIndex == -1 || frontIndex > rearIndex) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // ISEMPTY: Check if the queue has any active elements
    bool isEmpty() {
        return (frontIndex == -1 || frontIndex > rearIndex);
    }

    // SHOW: Print the active line from front to back
    void show() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue (Front to Rear): ";
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    // 1. Happy Path Test
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.show(); // Expected: 10 20 30

    cout << "Front is: " << q.front() << endl; // Expected: 10

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
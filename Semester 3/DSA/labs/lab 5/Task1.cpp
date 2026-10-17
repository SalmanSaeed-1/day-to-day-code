#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 5;

struct print_request {
    string studentName;
    int numPages;
};

class Queue {
private:
    print_request requests[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(string name, int pages) {
        if (isFull()) {
            cout << "Queue Overflow! The printer queue is full." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;

        requests[rear].studentName = name;
        requests[rear].numPages = pages;

        cout << "Print request added successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! There are no print requests." << endl;
            return;
        }

        cout << "\nCurrently processing:" << endl;
        cout << "Student: " << requests[front].studentName << endl;
        cout << "Pages: " << requests[front].numPages << endl;

        front++;

        // Queue becomes empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }

        cout << "Print request processed successfully." << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue Underflow! There are no print requests." << endl;
            return;
        }

        cout << "\nNext Print Request:" << endl;
        cout << "Student: " << requests[front].studentName << endl;
        cout << "Pages: " << requests[front].numPages << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty. There are no waiting print requests."<< endl;
            return;
        }

        cout << "\n===== WAITING PRINT REQUESTS =====" << endl;

        int number = 1;

        for (int i = front; i <= rear; i++) {
            cout << number << ". "<< "Student: " << requests[i].studentName<< ", Pages: " << requests[i].numPages<< endl;
            number++;
        }
    }
};

int main() {
    Queue q;
    int choice;

    do {
        cout << "\n===== UNIVERSITY PRINT QUEUE =====" << endl;
        cout << "1. Add Print Request" << endl;
        cout << "2. Process Print Request" << endl;
        cout << "3. View Next Request" << endl;
        cout << "4. Display Waiting Requests" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            string name;
            int pages;

            cin.ignore();

            cout << "Enter student name: ";
            getline(cin, name);

            cout << "Enter number of pages: ";
            cin >> pages;

            if (pages <= 0) {
                cout << "Number of pages must be greater than 0." << endl;
            }
            else {
                q.enqueue(name, pages);
            }

            break;
        }

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting Print Queue Management System..." << endl;
            break;

        default:
            cout << "Invalid choice! Please enter a number from 1 to 5." << endl;
        }

    } while (choice != 5);

    return 0;
}

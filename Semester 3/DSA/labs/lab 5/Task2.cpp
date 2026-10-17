#include <iostream>
#include <string>

using namespace std;

struct Node {
    int patient_id;
    string patient_name;
    int patient_age;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isempty() {
        return front == nullptr;
    }

    void enqueue(int pat_id, string pat_name, int pat_age) {
        Node* newNode = new Node;

        newNode->patient_age = pat_age;
        newNode->patient_id = pat_id;
        newNode->patient_name = pat_name;
        newNode->next = nullptr;

        if (isempty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "New patient added successfully." << endl;
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty!!" << endl;
            return;
        }

        cout << "Removing the patient: " << front->patient_name << endl;

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;

        cout << "Served and removed the patient successfully." << endl;
    }

    void peek() {
        if (isempty()) {
            cout << "Queue is empty!!" << endl;
            return;
        }

        cout << "\nNext patient to be served:" << endl;
        cout << "Patient name : " << front->patient_name << endl;
        cout << "Patient ID   : " << front->patient_id << endl;
        cout << "Patient age  : " << front->patient_age << endl;
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        int number = 1;

        cout << "\nWaiting patients:" << endl;

        while (temp != nullptr) {
            cout << "\nPatient Number: " << number << endl;
            cout << "Patient name : " << temp->patient_name << endl;
            cout << "Patient ID   : " << temp->patient_id << endl;
            cout << "Patient age  : " << temp->patient_age << endl;

            temp = temp->next;
            number++;
        }
    }

    void status() {
        if (isempty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            cout << "Queue contains waiting patients." << endl;
        }
    }

    ~Queue() {
        while (!isempty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;
    int choice;

    do {
        cout << "\n===== HOSPITAL PATIENT QUEUE =====" << endl;
        cout << "1. Register Patient" << endl;
        cout << "2. Serve Patient" << endl;
        cout << "3. View Next Patient" << endl;
        cout << "4. Display Waiting Patients" << endl;
        cout << "5. Check Queue Status" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int id;
            string name;
            int age;

            cin.ignore();

            cout << "Enter patient name: ";
            getline(cin, name);

            cout << "Enter Patient ID: ";
            cin >> id;

            cout << "Enter Patient Age: ";
            cin >> age;

            if (age <= 0 || id <= 0) {
                cout << "Patient ID and age must be greater than 0." << endl;
            }
            else {
                q.enqueue(id, name, age);
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
            q.status();
            break;

        case 6:
            cout << "Exiting Hospital Patient Queue System..." << endl;
            break;

        default:
            cout << "Invalid choice! Please enter a number from 1 to 6." << endl;
        }

    } while (choice != 6);

    return 0;
}

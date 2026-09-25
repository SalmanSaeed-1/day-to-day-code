#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;       // Data
    Node* next;     // Pointer to the next node
};

// Linked list class to manage nodes
class LinkedList {
private:
    Node* head;     // Pointer to the first node (head)
    Node* tail;     // Pointer to the last node (tail)

public:
    // Constructor
    LinkedList() {
        head = NULL;  
        tail = NULL;  
    }

    // Add a node at the front of the list
    void insertAtHead(int value) {
        Node* newNode = new Node;  
        newNode->data = value;
        newNode->next = head;  
        head = newNode;        

        // If list was empty, update tail too
        if (tail == NULL) {
            tail = newNode;
        }
    }

    // Add a node at the end of the list
    void insertAtTail(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (tail == NULL) { // List is empty
            head = tail = newNode;
        } else {
            tail->next = newNode; // Link last node to new node
            tail = newNode;       // Update tail
        }
    }

    // Insert node at a specific location (1-based index)
    void insertAtSpecificLocation(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) { // Insert at head
            insertAtHead(value);
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        Node* current = head;
        int count = 1;

        // Traverse to (position-1)th node
        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            cout << "Position out of range!" << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;

        // Update tail if inserted at the end
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    // Delete the first node
    void deleteAtHead() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        // If list becomes empty, reset tail
        if (head == NULL) {
            tail = NULL;
        }
    }

    // Delete the last node
    void deleteAtTail() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == NULL) { // Only one node
            delete head;
            head = tail = NULL;
            return;
        }

        Node* current = head;
        while (current->next != tail) { // Move to second-last node
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = NULL;
    }

    // Delete node at a specific location (1-based index)
    void deleteAtSpecificLocation(int position) {
        if (position <= 0 || head == NULL) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }

        if (position == 1) {
            deleteAtHead();
            return;
        }

        Node* current = head;
        int count = 1;

        // Traverse to (position-1)th node
        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }

        if (current == NULL || current->next == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;

        // If deleting last node, update tail
        if (temp == tail) {
            tail = current;
        }

        delete temp;
    }

    // Display the list
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function to test the linked list
int main() {
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.insertAtTail(40);
    list.insertAtTail(50);

    cout << "List after insertions: ";
    list.display();   // Expected: 30 -> 20 -> 10 -> 40 -> 50 -> NULL

    list.insertAtSpecificLocation(25, 3);
    cout << "After inserting 25 at position 3: ";
    list.display();   // Expected: 30 -> 20 -> 25 -> 10 -> 40 -> 50 -> NULL

    list.deleteAtHead();
    cout << "After deleting head: ";
    list.display();   // Expected: 20 -> 25 -> 10 -> 40 -> 50 -> NULL

    list.deleteAtTail();
    cout << "After deleting tail: ";
    list.display();   // Expected: 20 -> 25 -> 10 -> 40 -> NULL

    list.deleteAtSpecificLocation(2);
    cout << "After deleting node at position 2: ";
    list.display();   // Expected: 20 -> 10 -> 40 -> NULL

    return 0;
}


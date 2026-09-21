#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;       // Data
    Node* prev;     // Pointer to previous node
    Node* next;     // Pointer to next node
};

// Doubly Linked List Class
class DoublyLinkedList {
private:
    Node* head;     // First node
    Node* tail;     // Last node

public:
    // Constructor
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert at Head
    void insertAtHead(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;
        head = newNode;

        if (tail == NULL) // First node
            tail = newNode;
    }

    // Insert at Tail
    void insertAtTail(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = tail;

        if (tail != NULL)
            tail->next = newNode;
        tail = newNode;

        if (head == NULL) // First node
            head = newNode;
    }

    // Insert at Specific Location (1-based index)
    void insertAtSpecificLocation(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) {
            insertAtHead(value);
            return;
        }

        Node* current = head;
        int count = 1;

        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        // Insert in middle or at end
        Node* newNode = new Node;
        newNode->data = value;

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL)
            current->next->prev = newNode;
        else
            tail = newNode; // inserted at end

        current->next = newNode;
    }

    // Delete at Head
    void deleteAtHead() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL; // list became empty

        delete temp;
    }

    // Delete at Tail
    void deleteAtTail() {
        if (tail == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL; // list became empty

        delete temp;
    }

    // Delete at Specific Location (1-based index)
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

        while (current != NULL && count < position) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        if (current->prev != NULL)
            current->prev->next = current->next;
        if (current->next != NULL)
            current->next->prev = current->prev;
        else
            tail = current->prev; // deleting last node

        delete current;
    }

    // Display list forward
    void displayForward() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Display list backward
    void displayBackward() {
        Node* current = tail;
        while (current != NULL) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }
};

// Main function to test Doubly Linked List
int main() {
    DoublyLinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout << "List forward: ";
    list.displayForward();   // 20 <-> 10 <-> 30 <-> 40 -> NULL

    cout << "List backward: ";
    list.displayBackward();  // 40 <-> 30 <-> 10 <-> 20 -> NULL

    list.insertAtSpecificLocation(25, 3);
    cout << "After inserting 25 at pos 3: ";
    list.displayForward();   // 20 <-> 10 <-> 25 <-> 30 <-> 40 -> NULL

    list.deleteAtHead();
    cout << "After deleting head: ";
    list.displayForward();   // 10 <-> 25 <-> 30 <-> 40 -> NULL

    list.deleteAtTail();
    cout << "After deleting tail: ";
    list.displayForward();   // 10 <-> 25 <-> 30 -> NULL

    list.deleteAtSpecificLocation(2);
    cout << "After deleting node at pos 2: ";
    list.displayForward();   // 10 <-> 30 -> NULL

    return 0;
}


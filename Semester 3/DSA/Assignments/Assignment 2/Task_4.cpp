#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Helper to build the list
    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    // Function to change the head to the specified position
    bool positionHead(int pos) {
        // Return false if list is empty, has only one node, or pos is 0 (no change needed)
        if (head == nullptr || head->next == nullptr || pos <= 0) {
            return false;
        }

        // Calculate the length of the list to ensure pos is within bounds
        int length = 0;
        Node* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        if (pos >= length) {
            return false; // Position is out of bounds
        }

        // Traverse to find the new head at the specified index
        curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }

        // Identify the node that will become the new tail
        Node* newTail = curr->prev;

        // Temporarily connect the old tail to the old head to make it circular
        tail->next = head;
        head->prev = tail;

        // Break the links to establish the new head and tail properly
        newTail->next = nullptr;
        curr->prev = nullptr;

        // Update the class head and tail pointers
        head = curr;
        tail = newTail;

        return true;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.append(11);
    list.append(3);
    list.append(8);
    list.append(2);
    list.append(1);

    cout << "Initial list: ";
    list.displayList();

    int pos = 2;
    cout << "Calling positionHead(" << pos << ")" << endl;
    
    bool success = list.positionHead(pos);
    
    if (success) {
        cout << "List after changes: ";
        list.displayList();
    } else {
        cout << "Failed to reposition head (invalid position)." << endl;
    }

    return 0;
}
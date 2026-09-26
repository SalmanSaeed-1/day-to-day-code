#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Helper to build the list
    void append(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayList()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    void swapNodes(int valA, int valB)
    {
        if (valA == valB)
        {
            return; // Nothing to swap
        }

        Node *nodeA = nullptr;
        Node *nodeB = nullptr;
        Node *curr = head;

        // Verify nodes a and b are in the list
        while (curr != nullptr)
        {
            if (curr->data == valA)
                nodeA = curr;
            if (curr->data == valB)
                nodeB = curr;
            curr = curr->next;
        }

        if (nodeA == nullptr || nodeB == nullptr)
        {
            cout << "Checking again: One or both nodes not found in the list." << endl;
            return;
        }

        // Case 1: Nodes are adjacent A is right before B
        if (nodeA->next == nodeB)
        {
            nodeA->next = nodeB->next;
            nodeB->prev = nodeA->prev;

            if (nodeA->next != nullptr)
                nodeA->next->prev = nodeA;
            if (nodeB->prev != nullptr)
                nodeB->prev->next = nodeB;

            nodeB->next = nodeA;
            nodeA->prev = nodeB;
        }
        // Case 2: Nodes are adjacent B is right before A
        else if (nodeB->next == nodeA)
        {
            nodeB->next = nodeA->next;
            nodeA->prev = nodeB->prev;

            if (nodeB->next != nullptr)
                nodeB->next->prev = nodeB;
            if (nodeA->prev != nullptr)
                nodeA->prev->next = nodeA;

            nodeA->next = nodeB;
            nodeB->prev = nodeA;
        }
        // Case 3: Nodes are separated by one or more nodes
        else
        {
            Node *tempPrev = nodeA->prev;
            Node *tempNext = nodeA->next;

            nodeA->prev = nodeB->prev;
            nodeA->next = nodeB->next;

            nodeB->prev = tempPrev;
            nodeB->next = tempNext;

            if (nodeA->prev != nullptr)
                nodeA->prev->next = nodeA;
            if (nodeA->next != nullptr)
                nodeA->next->prev = nodeA;

            if (nodeB->prev != nullptr)
                nodeB->prev->next = nodeB;
            if (nodeB->next != nullptr)
                nodeB->next->prev = nodeB;
        }

        // Handling edge cases where head or tail pointers must change
        if (nodeA->prev == nullptr)
            head = nodeA;
        else if (nodeB->prev == nullptr)
            head = nodeB;

        if (nodeA->next == nullptr)
            tail = nodeA;
        else if (nodeB->next == nullptr)
            tail = nodeB;
    }
};

int main()
{
    DoublyLinkedList list;

    // Constructing the doubly linked list specified in the problem
    int elements[] = {3, 1, 8, 5, 4, 2, 9, 6, 7, 0};
    for (int i = 0; i < 10; i++)
    {
        list.append(elements[i]);
    }

    cout << "Initial list: ";
    list.displayList();

    // Testing Special Case: Adjacent nodes 5 and 4
    cout << "\nSwapping adjacent nodes (5 and 4):" << endl;
    list.swapNodes(5, 4);
    list.displayList();

    // Testing Special Case: Separated by one node 1 and 4
    cout << "\nSwapping nodes separated by one node (1 and 4):" << endl;
    list.swapNodes(1, 4);
    list.displayList();

    // Testing Special Case: Head and Tail 3 and 0
    cout << "\nSwapping head and tail (3 and 0):" << endl;
    list.swapNodes(3, 0);
    list.displayList();

    return 0;
}
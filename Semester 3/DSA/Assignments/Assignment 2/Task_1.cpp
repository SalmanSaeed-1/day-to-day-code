#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Helper function to print the list in the requested format
void printList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int detectAndRemoveLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return -1; // No loop possible
    }

    Node *slow = head, *fast = head;
    bool hasLoop = false;

    // Detect the loop
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            hasLoop = true;
            break;
        }
    }

    if (!hasLoop)
    {
        return -1; // No cycle detected
    }

    // Find the starting node of the loop and its index
    slow = head;
    int startIndex = 1;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        startIndex++;
    }

    Node *loopStart = slow;

    // Traverse to find the end node of the loop
    Node *curr = loopStart;
    int endIndex = startIndex;
    while (curr->next != loopStart)
    {
        curr = curr->next;
        endIndex++;
    }

    // Print where the loop starts and ends
    cout << "Loop starts at Node # " << startIndex << endl;
    cout << "Loop ends at Node # " << endIndex << endl;

    // Break the loop and print the removal message
    curr->next = nullptr;
    cout << "Loop removed from Node # " << endIndex << " > Node # " << startIndex << endl;

    // Return the value saved in the start node
    return loopStart->data;
}

int main()
{
    // Construct the linked list
    Node *head = new Node(11);
    head->next = new Node(3);
    head->next->next = new Node(8);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Create the cycle: Connect Node 5 back to Node 3
    head->next->next->next->next->next = head->next->next;

    // 1. Detect and remove the loop, capture returned value
    int returnedValue = detectAndRemoveLoop(head);

    // 2. Print returned value
    cout << "Value returned: " << returnedValue << endl;

    // 3. Print the list after removing the loop
    cout << "List after removing loop: ";
    printList(head);

    // 4. Check again to verify the loop is gone
    cout << "Checking again: ";
    if (detectAndRemoveLoop(head) == -1)
    {
        cout << "No loop found" << endl;
    }
    else
    {
        cout << "Loop found" << endl;
    }

    // Free memory
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
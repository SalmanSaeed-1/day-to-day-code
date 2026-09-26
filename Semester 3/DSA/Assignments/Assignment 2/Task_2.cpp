#include <iostream>
#include <string>
using namespace std;

// Create Person class
class Person
{
public:
    string name;
    string address;
    string phone;

    Person(string n = "", string a = "", string p = "")
    {
        name = n;
        address = a;
        phone = p;
    }
};

// Use Person as a data member in the Node struct
struct Node
{
    Person data;
    Node *next;

    Node(Person p)
    {
        data = p;
        next = nullptr;
    }
};

class AddressBookList
{
private:
    Node *head;

public:
    AddressBookList()
    {
        head = nullptr;
    }

    // Inserts the node in the right place as per alphabetical order
    void insert(Person p)
    {
        Node *newNode = new Node(p);

        if (head == nullptr || head->data.name >= p.name)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *curr = head;
        // Find the insertion point
        while (curr->next != nullptr && curr->next->data.name < p.name)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }

    // Find function for the list class by passing its name
    void find(string searchName)
    {
        Node *curr = head;

        while (curr != nullptr)
        {
            if (curr->data.name == searchName)
            {
                cout << "Record found for: " << searchName << endl;
                cout << "Address: " << curr->data.address << endl;
                cout << "Phone: " << curr->data.phone << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Checking again: No record found for " << searchName << endl;
    }

    // Prints the list
    void displayList()
    {
        Node *curr = head;

        if (curr == nullptr)
        {
            cout << "List is empty -> NULL" << endl;
            return;
        }

        cout << "Address Book List: ";
        while (curr != nullptr)
        {
            cout << curr->data.name << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    AddressBookList addressBook;
    int choice;
    string name, address, phone;

    while (true)
    {
        cout << "\n1. Add Person\n2. Find Person\n3. Display List\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // To clear the newline character from input buffer

        if (choice == 1)
        {
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter phone number: ";
            getline(cin, phone);

            Person newPerson(name, address, phone);
            addressBook.insert(newPerson);
            cout << "Person inserted." << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter name to find: ";
            getline(cin, name);
            addressBook.find(name);
        }
        else if (choice == 3)
        {
            addressBook.displayList();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
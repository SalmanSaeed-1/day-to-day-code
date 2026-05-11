#include <iostream>
#include <string>
using namespace std;

class book {
private:
    int bookid;
    string title;
    string author;
    bool isissued;

public:
    book() {
        bookid = 0;
        title = "Nill";
        author = "Nill";
        isissued = false;
    }

    book(int id, string title, string author) {
        bookid = id;
        this->title = title;
        this->author = author;
        isissued = false;
    }

    int getbookid() const {
        return bookid;
    }

    string gettitle() const {
        return title;
    }

    bool getissuedstatus() const {
        return isissued;
    }

    void issuebook() {
        if (isissued == true) {
            cout << "Book already issued" << endl;
            return;
        }

        isissued = true;
        cout << "Book issued successfully" << endl;
    }

    void returnbook() {
        if (isissued == false) {
            cout << "Book is not issued" << endl;
            return;
        }

        isissued = false;
        cout << "Book returned successfully" << endl;
    }

    void display() const {
        cout << "\nBook ID: " << bookid << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;

        if (isissued == true) {
            cout << "Status: Issued" << endl;
        }
        else {
            cout << "Status: Available" << endl;
        }
    }

    bool operator==(const book& b) const {
        return bookid == b.bookid;
    }

    friend void showbookstatus(book b) {
        if (b.isissued == true) {
            cout << "Book is already issued" << endl;
        }
        else {
            cout << "Book is available" << endl;
        }
    }
};

class library {
private:
    book* books;
    int count;
    int capacity;
    static int totalbooks;

public:
    library() {
        count = 0;
        capacity = 2;
        books = new book[capacity];
    }

    library(const library& lib) {
        count = lib.count;
        capacity = lib.capacity;

        books = new book[capacity];

        for (int i = 0; i < count; i++) {
            books[i] = lib.books[i];
        }
    }

    ~library() {
        delete[] books;
    }

    void addBook(book b) {
        for (int i = 0; i < count; i++) {
            if (books[i].getbookid() == b.getbookid()) {
                cout << "Book is already registered" << endl;
                return;
            }
        }

        if (count == capacity) {
            capacity = capacity * 2;

            book* temp = new book[capacity];

            for (int i = 0; i < count; i++) {
                temp[i] = books[i];
            }

            delete[] books;
            books = temp;
        }

        books[count] = b;
        count++;
        totalbooks++;

        cout << "Book added successfully" << endl;
    }

    void removebook(int bookid) {
        int index = -1;

        for (int i = 0; i < count; i++) {
            if (books[i].getbookid() == bookid) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Book not found" << endl;
            return;
        }

        for (int i = index; i < count - 1; i++) {
            books[i] = books[i + 1];
        }

        count--;
        totalbooks--;

        cout << "Book removed successfully" << endl;
    }

    void searchbook(int bookid) const {
        int index = -1;

        for (int i = 0; i < count; i++) {
            if (books[i].getbookid() == bookid) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Book not found" << endl;
        }
        else {
            cout << "Book found at index: " << index << endl;
            books[index].display();
        }
    }

    void issuebook(int bookid) {
        int index = -1;

        for (int i = 0; i < count; i++) {
            if (books[i].getbookid() == bookid) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Book not found" << endl;
        }
        else {
            books[index].issuebook();
        }
    }

    void returnbook(int bookid) {
        int index = -1;

        for (int i = 0; i < count; i++) {
            if (books[i].getbookid() == bookid) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Book not found" << endl;
        }
        else {
            books[index].returnbook();
        }
    }

    void displayallbooks() const {
        if (count == 0) {
            cout << "No books available in library" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            books[i].display();
        }
    }

    static int gettotalbooks() {
        return totalbooks;
    }
};

int library::totalbooks = 0;

class member {
protected:
    int memberid;
    string name;

public:
    member() {
        memberid = 0;
        name = "Nill";
    }

    member(int id, string name) {
        this->memberid = id;
        this->name = name;
    }

    virtual void displaymember() const {
        cout << "\nMember ID: " << memberid << endl;
        cout << "Name: " << name << endl;
    }
};

class librarian : public member {
private:
    int employeeid;

public:
    librarian() : member() {
        employeeid = 0;
    }

    librarian(int memberid, string name, int empid) : member(memberid, name) {
        this->employeeid = empid;
    }

    void displaymember() const {
        cout << "\nLibrarian Details" << endl;
        cout << "Member ID: " << memberid << endl;
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeid << endl;
    }
};

int main() {
    library lib;
    librarian l1(1, "Ali", 5001);

    int choice;

    while (true) {
        cout << "\n======= LIBRARY MANAGEMENT SYSTEM =======\n";
        cout << "1 - Add book\n";
        cout << "2 - Display all books\n";
        cout << "3 - Search book\n";
        cout << "4 - Issue book\n";
        cout << "5 - Return book\n";
        cout << "6 - Remove book\n";
        cout << "7 - Show total books\n";
        cout << "8 - Show librarian details\n";
        cout << "9 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;

            cout << "Enter book ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter book title: ";
            getline(cin, title);

            cout << "Enter author name: ";
            getline(cin, author);

            book b(id, title, author);
            lib.addBook(b);
        }

        else if (choice == 2) {
            lib.displayallbooks();
        }

        else if (choice == 3) {
            int id;

            cout << "Enter book ID to search: ";
            cin >> id;

            lib.searchbook(id);
        }

        else if (choice == 4) {
            int id;

            cout << "Enter book ID to issue: ";
            cin >> id;

            lib.issuebook(id);
        }

        else if (choice == 5) {
            int id;

            cout << "Enter book ID to return: ";
            cin >> id;

            lib.returnbook(id);
        }

        else if (choice == 6) {
            int id;

            cout << "Enter book ID to remove: ";
            cin >> id;

            lib.removebook(id);
        }

        else if (choice == 7) {
            cout << "Total books: " << library::gettotalbooks() << endl;
        }

        else if (choice == 8) {
            l1.displaymember();
        }

        else if (choice == 9) {
            cout << "Program ended" << endl;
            break;
        }

        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
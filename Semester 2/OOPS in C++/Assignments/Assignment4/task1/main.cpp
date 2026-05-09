#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class SimpleDate {
private:
    int day, month, year;

    int toDays() const {
        return year * 365 + month * 30 + day; // simple academic date model
    }

public:
    SimpleDate(int d = 1, int m = 1, int y = 2026) : day(d), month(m), year(y) {}

    SimpleDate addDays(int days) const {
        int total = toDays() + days;
        int y = total / 365;
        int rem = total % 365;
        int m = rem / 30;
        int d = rem % 30;
        if (d == 0) { d = 30; m--; }
        if (m == 0) { m = 12; y--; }
        return SimpleDate(d, m, y);
    }

    int daysAfter(const SimpleDate& other) const {
        return toDays() - other.toDays();
    }

    string str() const {
        string s = (day < 10 ? "0" : "") + to_string(day) + "-";
        s += (month < 10 ? "0" : "") + to_string(month) + "-" + to_string(year);
        return s;
    }
};

class Book {
protected:
    int id;
    string name, author, purchaseDate;
    int editionNumber;
    bool available;

public:
    Book(int i = 0, string n = "", string a = "", int e = 1, string pd = "")
        : id(i), name(n), author(a), purchaseDate(pd), editionNumber(e), available(true) {}

    virtual ~Book() {}
    int getId() const { return id; }
    string getName() const { return name; }
    bool isAvailable() const { return available; }
    void markIssued() { available = false; }
    void markAvailable() { available = true; }

    virtual string getType() const = 0;

    virtual void display() const {
        cout << left << setw(5) << id << setw(18) << name << setw(14) << author
             << setw(10) << getType() << setw(10) << editionNumber
             << (available ? "Available" : "Issued") << endl;
    }
};

class StudyBook : public Book {
public:
    StudyBook(int i, string n, string a, int e, string pd) : Book(i, n, a, e, pd) {}
    string getType() const override { return "StudyBook"; }
};

class Magazine : public Book {
public:
    Magazine(int i, string n, string a, int e, string pd) : Book(i, n, a, e, pd) {}
    string getType() const override { return "Magazine"; }
};

class Journal : public Book {
public:
    Journal(int i, string n, string a, int e, string pd) : Book(i, n, a, e, pd) {}
    string getType() const override { return "Journal"; }
};

class IssuedBook {
private:
    Book* book;            // aggregation: issued record refers to a library book
    SimpleDate issueDate;
    SimpleDate dueDate;

public:
    IssuedBook(Book* b = nullptr, SimpleDate i = SimpleDate(), SimpleDate d = SimpleDate())
        : book(b), issueDate(i), dueDate(d) {}

    Book* getBook() const { return book; }
    SimpleDate getDueDate() const { return dueDate; }

    void printReturnDate() const {
        if (book != nullptr)
            cout << book->getName() << " should be returned by " << dueDate.str() << endl;
    }

    int calculateFine(const SimpleDate& returnDate) const {
        int lateDays = returnDate.daysAfter(dueDate);
        return lateDays > 0 ? lateDays * 50 : 0; // Rs. 50 per late day
    }
};

class LibraryCard {
private:
    int cardId;
    int issueLimit;

public:
    LibraryCard(int c = 0, int limit = 0) : cardId(c), issueLimit(limit) {}
    int getLimit() const { return issueLimit; }
    int getCardId() const { return cardId; }
};

class Member {
protected:
    int registeredId;
    string name, address, phone;
    LibraryCard card;              // composition: card belongs to a member
    vector<IssuedBook> issuedBooks;

public:
    Member(int id, string n, string ad, string ph, int cardId, int limit)
        : registeredId(id), name(n), address(ad), phone(ph), card(cardId, limit) {}

    virtual ~Member() {}
    string getName() const { return name; }
    virtual string getType() const = 0;
    virtual int getIssueDays() const = 0;

    bool canIssueMore() const {
        return (int)issuedBooks.size() < card.getLimit();
    }

    void addIssuedBook(const IssuedBook& record) {
        issuedBooks.push_back(record);
    }

    bool returnBook(int bookId, const SimpleDate& returnDate) {
        for (int i = 0; i < (int)issuedBooks.size(); i++) {
            if (issuedBooks[i].getBook()->getId() == bookId) {
                int fine = issuedBooks[i].calculateFine(returnDate);
                cout << "Fine for " << name << " on book ID " << bookId << ": Rs. " << fine << endl;
                issuedBooks[i].getBook()->markAvailable();
                issuedBooks.erase(issuedBooks.begin() + i);
                return true;
            }
        }
        cout << "No issued book with ID " << bookId << " found for " << name << "." << endl;
        return false;
    }

    void displayReturnDates() const {
        cout << "\nReturn dates for " << name << ":\n";
        if (issuedBooks.empty()) {
            cout << "No books issued.\n";
            return;
        }
        for (const IssuedBook& record : issuedBooks)
            record.printReturnDate();
    }

    void displayStatus() const {
        cout << name << " (" << getType() << ") has " << issuedBooks.size()
             << " book(s) issued out of limit " << card.getLimit() << ".\n";
    }
};

class Student : public Member {
public:
    Student(int id, string n, string ad, string ph, int cardId)
        : Member(id, n, ad, ph, cardId, 3) {}

    string getType() const override { return "Student"; }
    int getIssueDays() const override { return 14; }
};

class Faculty : public Member {
public:
    Faculty(int id, string n, string ad, string ph, int cardId)
        : Member(id, n, ad, ph, cardId, 5) {}

    string getType() const override { return "Faculty"; }
    int getIssueDays() const override { return 60; }
};

class Library {
private:
    vector<Book*> books; // aggregation: library keeps records of book objects

public:
    ~Library() {
        for (Book* b : books)
            delete b;
    }

    void addBook(Book* book) {
        books.push_back(book);
    }

    Book* searchBook(int id) {
        for (Book* b : books)
            if (b->getId() == id)
                return b;
        return nullptr;
    }

    bool issueBook(Member& member, int bookId, const SimpleDate& issueDate) {
        Book* book = searchBook(bookId);
        if (book == nullptr) {
            cout << "Book ID " << bookId << " not found.\n";
            return false;
        }
        if (!book->isAvailable()) {
            cout << book->getName() << " is already issued, so it cannot be issued twice.\n";
            return false;
        }
        if (!member.canIssueMore()) {
            cout << member.getName() << " has reached the issuance limit.\n";
            return false;
        }

        book->markIssued();
        SimpleDate dueDate = issueDate.addDays(member.getIssueDays());
        member.addIssuedBook(IssuedBook(book, issueDate, dueDate));
        cout << book->getName() << " issued to " << member.getName()
             << ". Due date: " << dueDate.str() << endl;
        return true;
    }

    void showBooks() const {
        cout << "\nLibrary Book Records:\n";
        cout << left << setw(5) << "ID" << setw(18) << "Name" << setw(14) << "Author"
             << setw(10) << "Type" << setw(10) << "Edition" << "Status\n";
        for (Book* b : books)
            b->display();
    }
};

class Librarian {
private:
    int librarianId;
    string name, username, password;

public:
    Librarian(int id, string n, string u, string p)
        : librarianId(id), name(n), username(u), password(p) {}

    bool login(string u, string p) const {
        return username == u && password == p;
    }

    void addBookToLibrary(Library& library, Book* book) {
        library.addBook(book);
    }
};

int main() {
    Library library;
    Librarian librarian(1, "Ali", "admin", "1234");

    if (librarian.login("admin", "1234")) {
        cout << "Librarian login successful.\n";

        librarian.addBookToLibrary(library, new StudyBook(101, "OOP Basics", "Sajid", 1, "01-01-2026"));
        librarian.addBookToLibrary(library, new StudyBook(102, "C++ Guide", "Bjarne", 4, "02-01-2026"));
        librarian.addBookToLibrary(library, new StudyBook(103, "Data Structures", "Malik", 2, "03-01-2026"));
        librarian.addBookToLibrary(library, new Magazine(104, "Tech Today", "EditorA", 5, "04-01-2026"));
        librarian.addBookToLibrary(library, new Magazine(105, "Science Mag", "EditorB", 3, "05-01-2026"));
        librarian.addBookToLibrary(library, new Journal(106, "AI Journal", "Dr. Khan", 1, "06-01-2026"));
        librarian.addBookToLibrary(library, new Journal(107, "ML Journal", "Dr. Sara", 1, "07-01-2026"));
        librarian.addBookToLibrary(library, new Journal(108, "Networks", "Dr. Noor", 2, "08-01-2026"));
        librarian.addBookToLibrary(library, new Magazine(109, "History Weekly", "EditorC", 6, "09-01-2026"));
        librarian.addBookToLibrary(library, new StudyBook(110, "DBMS Notes", "Date", 3, "10-01-2026"));
    }

    Student s1(201, "Student 1", "Lahore", "0300-1111111", 501);
    Student s2(202, "Student 2", "Lahore", "0300-2222222", 502);
    Student s3(203, "Student 3", "Lahore", "0300-3333333", 503);
    Faculty f1(301, "Faculty 1", "Lahore", "0300-4444444", 601);
    Faculty f2(302, "Faculty 2", "Lahore", "0300-5555555", 602);

    SimpleDate issueDate(1, 1, 2026);

    cout << "\nIssuing books:\n";
    library.issueBook(s1, 101, issueDate);
    library.issueBook(s1, 102, issueDate);
    library.issueBook(s1, 104, issueDate);

    library.issueBook(s2, 106, issueDate);

    library.issueBook(s3, 105, issueDate);
    library.issueBook(s3, 103, issueDate);

    library.issueBook(f1, 107, issueDate);
    library.issueBook(f1, 108, issueDate);
    library.issueBook(f1, 110, issueDate);

    library.issueBook(f2, 101, issueDate); // this line proves same book cannot be issued twice

    s1.displayReturnDates();

    cout << "\nReturning Student 2's book late:\n";
    SimpleDate lateReturn(25, 1, 2026);
    s2.returnBook(106, lateReturn);

    cout << "\nUpdated status:\n";
    s2.displayStatus();
    library.showBooks();

    return 0;
}

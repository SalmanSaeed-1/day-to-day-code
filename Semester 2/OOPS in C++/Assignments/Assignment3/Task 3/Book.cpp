#include "Book.h"
#include <stdexcept>

Book::Book() : pageCount(0), capacity(10) {
    pages = new Page*[capacity];
    for (int i = 0; i < capacity; i++)
        pages[i] = new Page();
    // Book with default capacity starts with empty pages
    // We track how many have been "used"
}

Book::Book(int cap) : pageCount(0), capacity(cap) {
    if (capacity <= 0) capacity = 1;
    pages = new Page*[capacity];
    for (int i = 0; i < capacity; i++)
        pages[i] = new Page();
}

Book::Book(const Book& other) : pageCount(other.pageCount), capacity(other.capacity) {
    pages = new Page*[capacity];
    for (int i = 0; i < capacity; i++) {
        if (other.pages[i])
            pages[i] = new Page(*other.pages[i]);
        else
            pages[i] = new Page();
    }
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        for (int i = 0; i < capacity; i++) {
            delete pages[i];
        }
        delete[] pages;

        capacity  = other.capacity;
        pageCount = other.pageCount;
        pages = new Page*[capacity];
        for (int i = 0; i < capacity; i++) {
            if (other.pages[i])
                pages[i] = new Page(*other.pages[i]);
            else
                pages[i] = new Page();
        }
    }
    return *this;
}

Book::~Book() {
    for (int i = 0; i < capacity; i++) {
        delete pages[i];
        pages[i] = nullptr;
    }
    delete[] pages;
}

// Add a page to the book.
// The rule: current page must be filled before moving to the next.
// In practice we follow the sample main which adds whole pages in sequence.
// We put the page content into the next available slot.
Book& Book::operator+=(const Page& page) {
    if (pageCount < capacity) {
        delete pages[pageCount];
        pages[pageCount] = new Page(page);
        pageCount++;
    }
    return *this;
}

Page& Book::operator[](int idx) {
    if (idx < 0 || idx >= capacity || pages[idx] == nullptr)
        throw std::out_of_range("Page index out of range");
    return *pages[idx];
}

const Page& Book::operator[](int idx) const {
    if (idx < 0 || idx >= capacity || pages[idx] == nullptr)
        throw std::out_of_range("Page index out of range");
    return *pages[idx];
}

Book Book::operator+(const Book& other) const {
    int newCap = capacity + other.capacity;
    Book result(newCap);
    // copy this book's pages
    for (int i = 0; i < capacity; i++) {
        delete result.pages[i];
        result.pages[i] = new Page(*pages[i]);
    }
    // copy other book's pages
    for (int i = 0; i < other.capacity; i++) {
        delete result.pages[capacity + i];
        result.pages[capacity + i] = new Page(*other.pages[i]);
    }
    result.pageCount = pageCount + other.pageCount;
    return result;
}

ostream& operator<<(ostream& out, const Book& b) {
    for (int i = 0; i < b.capacity; i++) {
        if (b.pages[i] && b.pages[i]->getLineCount() > 0) {
            out << "--- Page " << (i + 1) << " ---\n";
            out << *b.pages[i];
            out << "\n";
        }
    }
    return out;
}

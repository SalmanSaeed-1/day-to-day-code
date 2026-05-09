#ifndef BOOK_H
#define BOOK_H

#include "Page.h"

class Book {
private:
    Page** pages;
    int    pageCount;
    int    capacity;

public:
    Book();
    Book(int capacity);
    Book(const Book& other);
    Book& operator=(const Book& other);
    ~Book();

    int getPageCount() const { return pageCount; }
    int getCapacity()  const { return capacity;  }

    // Add a Page to the book — current page must be filled first
    Book& operator+=(const Page& page);

    // Access a specific page
    Page& operator[](int idx);
    const Page& operator[](int idx) const;

    // Concatenate two books
    Book operator+(const Book& other) const;

    friend ostream& operator<<(ostream& out, const Book& b);
};

ostream& operator<<(ostream& out, const Book& b);

#endif

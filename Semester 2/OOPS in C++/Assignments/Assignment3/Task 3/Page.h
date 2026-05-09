#ifndef PAGE_H
#define PAGE_H

#include "Line.h"

const int MAX_LINES = 20;

class Page {
private:
    Line** lines;
    int    lineCount;

public:
    Page();
    Page(const Page& other);
    Page& operator=(const Page& other);
    ~Page();

    int  getLineCount() const { return lineCount; }
    bool isFull() const { return lineCount >= MAX_LINES; }

    // Add text (char array) to page — handles overflow to next lines
    Page& operator+=(const char* text);

    // Add a Line object to page
    Page& operator+=(const Line& line);

    // Merge another page's lines into this page
    Page& operator+=(const Page& page);

    // Access a specific line
    Line& operator[](int idx);
    const Line& operator[](int idx) const;

    friend ostream& operator<<(ostream& out, const Page& p);
};

ostream& operator<<(ostream& out, const Page& p);

#endif

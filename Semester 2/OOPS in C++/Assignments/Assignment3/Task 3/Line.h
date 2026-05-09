#ifndef LINE_H
#define LINE_H

#include <iostream>
using namespace std;

const int MAX_LINE_CHARS = 40;

class Line {
private:
    char* text;
    int   length;

    static int myStrLen(const char* s);
    static void myStrCpy(char* dst, const char* src);
    static void myStrCat(char* dst, const char* src);

public:
    Line();
    Line(const char* str);
    Line(const Line& other);
    Line& operator=(const Line& other);
    Line& operator=(const char* str);
    ~Line();

    int  getLength() const { return length; }
    const char* getText() const { return text; }
    bool isFull() const { return length >= MAX_LINE_CHARS; }
    int  freeSpace() const { return MAX_LINE_CHARS - length; }

    // Append text to line, returns number of characters actually appended
    int append(const char* str, int startPos = 0);

    friend ostream& operator<<(ostream& out, const Line& l);
};

ostream& operator<<(ostream& out, const Line& l);

#endif

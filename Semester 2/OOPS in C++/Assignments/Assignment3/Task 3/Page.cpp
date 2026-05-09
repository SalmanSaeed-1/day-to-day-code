#include "Page.h"
#include <stdexcept>

static int pageStrLen(const char* s) {
    int i = 0;
    while (s && s[i] != '\0') i++;
    return i;
}

Page::Page() : lineCount(0) {
    lines = new Line*[MAX_LINES];
    for (int i = 0; i < MAX_LINES; i++)
        lines[i] = nullptr;
}

Page::Page(const Page& other) : lineCount(other.lineCount) {
    lines = new Line*[MAX_LINES];
    for (int i = 0; i < MAX_LINES; i++) {
        if (i < lineCount && other.lines[i])
            lines[i] = new Line(*other.lines[i]);
        else
            lines[i] = nullptr;
    }
}

Page& Page::operator=(const Page& other) {
    if (this != &other) {
        for (int i = 0; i < MAX_LINES; i++) {
            delete lines[i];
            lines[i] = nullptr;
        }
        lineCount = other.lineCount;
        for (int i = 0; i < lineCount; i++) {
            if (other.lines[i])
                lines[i] = new Line(*other.lines[i]);
        }
    }
    return *this;
}

Page::~Page() {
    for (int i = 0; i < MAX_LINES; i++) {
        delete lines[i];
        lines[i] = nullptr;
    }
    delete[] lines;
}

Page& Page::operator+=(const char* text) {
    if (!text) return *this;
    int pos = 0;
    int totalLen = pageStrLen(text);

    // skip leading spaces
    while (pos < totalLen && text[pos] == ' ') pos++;

    while (pos < totalLen && lineCount < MAX_LINES) {
        // find or create a line that has space
        Line* currentLine = nullptr;
        if (lineCount > 0 && !lines[lineCount - 1]->isFull()) {
            currentLine = lines[lineCount - 1];
        } else if (lineCount < MAX_LINES) {
            lines[lineCount] = new Line();
            currentLine = lines[lineCount];
            lineCount++;
        } else {
            break; // page is full
        }

        int newPos = currentLine->append(text, pos);
        if (newPos == pos) {
            // couldn't fit any word — if line already has content, try a new line
            if (currentLine->getLength() > 0 && lineCount < MAX_LINES) {
                lines[lineCount] = new Line();
                lineCount++;
                continue;
            } else {
                // even an empty line can't fit this word (shouldn't happen with 40 char limit)
                break;
            }
        }
        pos = newPos;
        // skip spaces
        while (pos < totalLen && text[pos] == ' ') pos++;
    }
    return *this;
}

Page& Page::operator+=(const Line& line) {
    if (lineCount < MAX_LINES) {
        lines[lineCount] = new Line(line);
        lineCount++;
    }
    return *this;
}

Page& Page::operator+=(const Page& page) {
    for (int i = 0; i < page.lineCount && lineCount < MAX_LINES; i++) {
        if (page.lines[i])
            *this += *page.lines[i];
    }
    return *this;
}

Line& Page::operator[](int idx) {
    if (idx < 0 || idx >= lineCount || lines[idx] == nullptr)
        throw std::out_of_range("Line index out of range");
    return *lines[idx];
}

const Line& Page::operator[](int idx) const {
    if (idx < 0 || idx >= lineCount || lines[idx] == nullptr)
        throw std::out_of_range("Line index out of range");
    return *lines[idx];
}

ostream& operator<<(ostream& out, const Page& p) {
    for (int i = 0; i < p.lineCount; i++) {
        if (p.lines[i])
            out << *p.lines[i] << "\n";
    }
    return out;
}

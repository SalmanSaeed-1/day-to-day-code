#include "Line.h"

int Line::myStrLen(const char* s) {
    int i = 0;
    while (s && s[i] != '\0') i++;
    return i;
}

void Line::myStrCpy(char* dst, const char* src) {
    int i = 0;
    while (src && src[i] != '\0') { dst[i] = src[i]; i++; }
    dst[i] = '\0';
}

void Line::myStrCat(char* dst, const char* src) {
    int dLen = myStrLen(dst);
    int i = 0;
    while (src && src[i] != '\0') { dst[dLen + i] = src[i]; i++; }
    dst[dLen + i] = '\0';
}

Line::Line() : length(0) {
    text = new char[MAX_LINE_CHARS + 1];
    text[0] = '\0';
}

Line::Line(const char* str) : length(0) {
    text = new char[MAX_LINE_CHARS + 1];
    text[0] = '\0';
    if (str) {
        int len = myStrLen(str);
        if (len > MAX_LINE_CHARS) len = MAX_LINE_CHARS;
        for (int i = 0; i < len; i++) text[i] = str[i];
        text[len] = '\0';
        length = len;
    }
}

Line::Line(const Line& other) : length(other.length) {
    text = new char[MAX_LINE_CHARS + 1];
    myStrCpy(text, other.text);
}

Line& Line::operator=(const Line& other) {
    if (this != &other) {
        myStrCpy(text, other.text);
        length = other.length;
    }
    return *this;
}

Line& Line::operator=(const char* str) {
    if (str) {
        int len = myStrLen(str);
        if (len > MAX_LINE_CHARS) len = MAX_LINE_CHARS;
        for (int i = 0; i < len; i++) text[i] = str[i];
        text[len] = '\0';
        length = len;
    } else {
        text[0] = '\0';
        length = 0;
    }
    return *this;
}

Line::~Line() {
    delete[] text;
    text = nullptr;
}

// Appends words from str starting at startPos.
// Words that don't fit are NOT appended (no word splitting).
// Returns index in str where appending stopped.
int Line::append(const char* str, int startPos) {
    if (!str) return startPos;
    int strLen = myStrLen(str);
    int pos = startPos;

    // skip leading spaces at startPos
    while (pos < strLen && str[pos] == ' ') pos++;

    while (pos < strLen) {
        // find end of next word
        int wordStart = pos;
        while (pos < strLen && str[pos] != ' ') pos++;
        int wordLen = pos - wordStart;

        // check if word fits (include space if not first word on line)
        int needed = wordLen + (length > 0 ? 1 : 0);
        if (length + needed > MAX_LINE_CHARS) {
            // word doesn't fit — stop here
            return wordStart;
        }

        // add space separator if line already has content
        if (length > 0) {
            text[length++] = ' ';
            text[length] = '\0';
        }
        // copy word
        for (int i = 0; i < wordLen; i++) {
            text[length++] = str[wordStart + i];
        }
        text[length] = '\0';

        // skip spaces after word
        while (pos < strLen && str[pos] == ' ') pos++;
    }
    return pos; // all text consumed
}

ostream& operator<<(ostream& out, const Line& l) {
    out << l.text;
    return out;
}

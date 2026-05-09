#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    Array();
    Array(int size);
    Array(int* arr, int size);
    Array(const Array&);

    int& operator[](int i);
    int& operator[](int i) const;
    const Array& operator=(const Array&);
    Array operator+(const Array&);
    Array operator-(const Array&);
    Array operator++();
    Array operator++(int);
    Array& operator--(int);
    bool operator==(const Array&) const;
    bool operator!();
    void operator+=(const Array&);
    void operator-=(const Array&);
    int operator()(int idx, int val);

    int getSize() const { return size; }

    ~Array();

    friend ostream& operator<<(ostream& output, const Array&);
    friend istream& operator>>(istream& input, Array&);
};

ostream& operator<<(ostream& output, const Array&);
istream& operator>>(istream& input, Array&);

#endif

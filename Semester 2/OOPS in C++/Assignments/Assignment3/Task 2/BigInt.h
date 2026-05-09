#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
using namespace std;

class BigInt {
private:
    int* digits;    // stored in reverse: digits[0] = least significant
    int  numDigits;
    bool negative;

    void fromInt(int val);
    void fromString(const char* text);
    void trim();
    BigInt& assign(const BigInt& other);

    static int  strLen(const char* s);
    static int  compareMagnitude(const BigInt& a, const BigInt& b);
    static BigInt addMagnitude(const BigInt& a, const BigInt& b);
    static BigInt subMagnitude(const BigInt& a, const BigInt& b); // |a|>=|b|

public:
    BigInt(int val = 0);
    BigInt(const char* text);
    BigInt(const BigInt& copy);
    BigInt& operator=(const BigInt& other);

    // Arithmetic
    BigInt operator+(const BigInt& val) const;
    BigInt operator+(int val) const;
    BigInt operator-(const BigInt& val) const;
    BigInt operator-(int val) const;
    BigInt operator*(const BigInt& val) const;

    // Compound assignment
    BigInt operator+=(const BigInt& rhs);
    BigInt operator-=(const BigInt& rhs);
    BigInt operator*=(const BigInt& rhs);

    // Comparison
    bool operator==(const BigInt& val) const;
    bool operator==(const char* val) const;
    bool operator!=(const BigInt& val) const;
    bool operator<(const BigInt& val) const;
    bool operator<=(const BigInt& val) const;
    bool operator>(const BigInt& val) const;
    bool operator>=(const BigInt& val) const;

    // Unary
    BigInt& operator++();
    BigInt  operator++(int);
    BigInt& operator--();
    BigInt  operator--(int);

    // Conversion: returns number of digits
    operator int() const;

    ~BigInt();

    char* toCharArray() const;

    friend ostream& operator<<(ostream& output, const BigInt& val);
    friend istream& operator>>(istream& input, BigInt& val);
};

ostream& operator<<(ostream& output, const BigInt& val);
istream& operator>>(istream& input, BigInt& val);

#endif

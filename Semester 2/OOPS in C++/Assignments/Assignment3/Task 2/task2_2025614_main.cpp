#include <iostream>
#include "BigInt.h"
using namespace std;

int main() {
    cout << "=== Task 2: BigInt Class Tests ===" << endl;

    BigInt a(12345);
    BigInt b(67890);
    cout << "a = " << a << ", b = " << b << endl;

    // Addition
    cout << "a + b = " << (a + b) << endl;
    cout << "a + 100 = " << (a + 100) << endl;

    // Subtraction
    cout << "b - a = " << (b - a) << endl;
    cout << "a - b = " << (a - b) << endl;

    // Multiplication
    cout << "a * b = " << (a * b) << endl;

    // Large number
    BigInt big("99999999999999999999999999999");
    BigInt one(1);
    cout << "big + 1 = " << (big + one) << endl;

    // Factorial of 20
    BigInt fact(1);
    for (int i = 2; i <= 20; i++)
        fact *= BigInt(i);
    cout << "20! = " << fact << endl;

    // Factorial of 30
    BigInt fact30(1);
    for (int i = 2; i <= 30; i++)
        fact30 *= BigInt(i);
    cout << "30! = " << fact30 << endl;

    // Comparison
    BigInt x("12345"), y("12345"), z("99999");
    cout << "x == y: " << (x == y ? "true" : "false") << endl;
    cout << "x == \"12345\": " << (x == "12345" ? "true" : "false") << endl;
    cout << "x < z: " << (x < z ? "true" : "false") << endl;
    cout << "z > x: " << (z > x ? "true" : "false") << endl;
    cout << "x != z: " << (x != z ? "true" : "false") << endl;
    cout << "x <= y: " << (x <= y ? "true" : "false") << endl;
    cout << "x >= y: " << (x >= y ? "true" : "false") << endl;

    // Compound assignment
    BigInt c(100);
    c += BigInt(50);
    cout << "100 += 50: " << c << endl;
    c -= BigInt(30);
    cout << " -= 30: " << c << endl;
    c *= BigInt(3);
    cout << " *= 3: " << c << endl;

    // Increment / Decrement
    BigInt d(10);
    cout << "d = " << d << endl;
    cout << "++d = " << (++d) << endl;
    cout << "d++ = " << (d++) << " (d now " << d << ")" << endl;
    cout << "--d = " << (--d) << endl;
    cout << "d-- = " << (d--) << " (d now " << d << ")" << endl;

    // Conversion operator (returns number of digits)
    BigInt n(123456789);
    cout << "Number of digits in " << n << ": " << (int)n << endl;

    // Negative numbers
    BigInt neg(-500);
    BigInt pos(300);
    cout << "neg = " << neg << ", pos = " << pos << endl;
    cout << "neg + pos = " << (neg + pos) << endl;
    cout << "neg * pos = " << (neg * pos) << endl;

    return 0;
}

#include <iostream>
#include "array.h"
using namespace std;

int main() {
    cout << "=== Task 1: Array Class Tests ===" << endl;

    // Default constructor
    Array a1;
    cout << "Default: " << a1 << " | Empty? " << (!a1 ? "Yes" : "No") << endl;

    // Parameterized constructor
    Array a2(5);
    cout << "Size-5 zeros: " << a2 << endl;

    // Array from existing int[]
    int raw[] = {10, 20, 30, 40, 50};
    Array a3(raw, 5);
    cout << "From raw[]: " << a3 << endl;

    // Copy constructor
    Array a4(a3);
    cout << "Copy of a3: " << a4 << endl;

    // Subscript operator
    a2[0] = 1; a2[1] = 2; a2[2] = 3; a2[3] = 4; a2[4] = 5;
    cout << "a2 after assignment: " << a2 << endl;
    cout << "a2[2] = " << a2[2] << endl;

    // Out of range
    try {
        int x = a2[10];
        (void)x;
    } catch (const out_of_range& e) {
        cout << "Out-of-range caught: " << e.what() << endl;
    }

    // operator=
    Array a5;
    a5 = a3;
    cout << "a5 = a3: " << a5 << endl;

    // operator+
    Array sum = a2 + a3;
    cout << "a2 + a3: " << sum << endl;

    // operator-
    Array diff = a3 - a2;
    cout << "a3 - a2: " << diff << endl;

    // operator++ (pre)
    Array a6(a2);
    ++a6;
    cout << "++a2 copy: " << a6 << endl;

    // operator++ (post)
    Array a7(a2);
    Array a8 = a7++;
    cout << "Post-increment original: " << a8 << " | after: " << a7 << endl;

    // operator-- (post)
    Array a9(a2);
    a9--;
    cout << "a9-- result: " << a9 << endl;

    // operator==
    cout << "a3 == a4: " << (a3 == a4 ? "true" : "false") << endl;
    cout << "a2 == a3: " << (a2 == a3 ? "true" : "false") << endl;

    // operator!
    cout << "!a1 (empty): " << (!a1 ? "true" : "false") << endl;
    cout << "!a2 (non-empty): " << (!a2 ? "true" : "false") << endl;

    // operator+=
    Array a10(a2);
    a10 += a3;
    cout << "a2 += a3: " << a10 << endl;

    // operator-=
    Array a11(a3);
    a11 -= a2;
    cout << "a3 -= a2: " << a11 << endl;

    // operator() - erase
    int arr2[] = {5, 10, 15, 20, 25};
    Array a12(arr2, 5);
    cout << "Before erase: " << a12 << endl;
    int res = a12(2, 15); // erase val 15 at idx 2
    cout << "After erase idx=2 val=15 (ret=" << res << "): " << a12 << endl;
    int res2 = a12(0, 99); // wrong value
    cout << "Erase wrong val (ret=" << res2 << "): " << a12 << endl;

    // >> operator
    Array a13(3);
    cout << "Enter 3 integers: ";
    cin >> a13;
    cout << "You entered: " << a13 << endl;

    return 0;
}

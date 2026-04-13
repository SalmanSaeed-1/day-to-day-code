#include <iostream>

using namespace std;


class A {
    int x;
public:
    A(int v): x(v) {}
    A operator+(A obj) { return A(x + obj.x); }
    A operator++(int) { A t=*this; x+=2; return t; }
    friend ostream& operator<<(ostream&, A);
};

ostream& operator<<(ostream& out, A a) {
    out << a.x;
    return out;
}

int main() {
    A a(3), b(4);
    A c = a++ + b;
    cout << a << " " << c;
}
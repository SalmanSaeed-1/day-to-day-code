#include <iostream>
using namespace std;

int countDigits(int n)
{
    if (n == 0)
        return 0;

    return 1 + countDigits(n / 10);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Number of digits = " << countDigits(n);

    return 0;
}

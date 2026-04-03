#include <iostream>

using namespace std;

class Counter
{
    int count;

public:
    Counter(int c)
    {
        count = c;
    }

    int operator++()
    {
        ++count;
        return count;
    }

    int operator++(int)
    {
        count++;
        return count;
    }

    void display()
    {
        cout << count;
    }
};

int main()
{
    Counter c(5);
    ++c;
    c.display();
    cout << endl;
    c++;
    c.display();
}
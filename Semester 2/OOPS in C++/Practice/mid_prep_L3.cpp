#include <iostream>

using namespace std;

int main()
{
    int *ptr = new int;
    int y = 50;
    ptr = &y;
    cout << *ptr;
    ptr = NULL;

    float *ptr2 = new float;
    *ptr2 = 50;
    cout << *ptr2;
    cout << endl;
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << endl;
    }

    delete[] arr;
    arr = nullptr;
    int size;
    char name[70];
    cout << "How many student you want to store in an array : ";
    cin >> size;
    int *arr2 = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter name of student : ";
        cin >> arr2[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << endl;
    }
    delete[] arr2;
    arr2 = nullptr;
    int n;
    int max = 5;
    n = max;
    int *array = new int[max];
    for (int i = 0; i < max; i++)
    {
        cout << "Enter " << i + 1 << " value for array : ";
        cin >> array[i];
    }

    char check;
    do
    {
        cout << "Do you want to enter more values : ";
        cin >> check;

        if (check == 'y' || check == 'Y')
        {
            max = max + 1;
            int *temp = new int[max];
            for (int i = 0; i < n; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;

            cout << "Enter another value : ";
            cin >> array[n];
            n++;
        }
        else
        {
            break;
        }
    } while (check == 'y' || check == 'Y');

    cout << endl
         << "Array values : ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
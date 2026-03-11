#include<iostream>
using namespace std;

int main() {
    int capacity = 5;
    int count = 0;

    int* arr = new int[capacity];

    for (int i = 0; i < capacity; i++) {
        cout << "Enter " << i + 1 << " value : ";
        cin >> arr[i];
        count++;
    }

    char check;
    do {
        cout << "Do you want to enter more values : press Y : ";
        cin >> check;

        if (check == 'y' || check == 'Y') {
            if (count == capacity) {
                capacity = capacity * 2;

                int* new_arr = new int[capacity];
                for (int i = 0; i < count; i++) {
                    new_arr[i] = arr[i];
                }

                delete[] arr;
                arr = new_arr;
            }

            cout << "Enter value of " << count + 1 << " : ";
            cin >> arr[count];
            count++;
        }
        else {
            break;
        }

    } while (check == 'y' || check == 'Y');

    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}
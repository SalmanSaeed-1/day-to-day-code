#include "array.h"
#include <stdexcept>

// Default constructor
Array::Array() : data(nullptr), size(0) {}

// Parameterized constructor
Array::Array(int size) : size(size) {
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = 0;
    } else {
        data = nullptr;
        this->size = 0;
    }
}

// Constructor from existing array
Array::Array(int* arr, int size) : size(size) {
    if (size > 0 && arr != nullptr) {
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = arr[i];
    } else {
        data = nullptr;
        this->size = 0;
    }
}

// Copy constructor
Array::Array(const Array& other) : size(other.size) {
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    } else {
        data = nullptr;
    }
}

// Subscript operator (non-const)
int& Array::operator[](int i) {
    if (i < 0 || i >= size)
        throw out_of_range("Index out of range");
    return data[i];
}

// Subscript operator (const)
int& Array::operator[](int i) const {
    if (i < 0 || i >= size)
        throw out_of_range("Index out of range");
    return data[i];
}

// Assignment operator
const Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++)
                data[i] = other.data[i];
        } else {
            data = nullptr;
        }
    }
    return *this;
}

// Addition operator
Array Array::operator+(const Array& other) {
    int newSize = (size > other.size) ? size : other.size;
    Array result(newSize);
    for (int i = 0; i < size; i++)
        result.data[i] += data[i];
    for (int i = 0; i < other.size; i++)
        result.data[i] += other.data[i];
    return result;
}

// Subtraction operator
Array Array::operator-(const Array& other) {
    int newSize = (size > other.size) ? size : other.size;
    Array result(newSize);
    for (int i = 0; i < size; i++)
        result.data[i] += data[i];
    for (int i = 0; i < other.size; i++)
        result.data[i] -= other.data[i];
    return result;
}

// Pre-increment (adds 1 to each element)
Array Array::operator++() {
    for (int i = 0; i < size; i++)
        data[i]++;
    return *this;
}

// Post-increment (adds 1 to each element, returns old)
Array Array::operator++(int) {
    Array temp(*this);
    for (int i = 0; i < size; i++)
        data[i]++;
    return temp;
}

// Post-decrement (subtracts 1 from each element)
Array& Array::operator--(int) {
    for (int i = 0; i < size; i++)
        data[i]--;
    return *this;
}

// Equality operator
bool Array::operator==(const Array& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; i++)
        if (data[i] != other.data[i]) return false;
    return true;
}

// Logical NOT (true if array is empty)
bool Array::operator!() {
    return size == 0 || data == nullptr;
}

// += operator
void Array::operator+=(const Array& other) {
    int newSize = (size > other.size) ? size : other.size;
    int* newData = new int[newSize];
    for (int i = 0; i < newSize; i++) newData[i] = 0;
    for (int i = 0; i < size; i++) newData[i] += data[i];
    for (int i = 0; i < other.size; i++) newData[i] += other.data[i];
    delete[] data;
    data = newData;
    size = newSize;
}

// -= operator
void Array::operator-=(const Array& other) {
    int newSize = (size > other.size) ? size : other.size;
    int* newData = new int[newSize];
    for (int i = 0; i < newSize; i++) newData[i] = 0;
    for (int i = 0; i < size; i++) newData[i] += data[i];
    for (int i = 0; i < other.size; i++) newData[i] -= other.data[i];
    delete[] data;
    data = newData;
    size = newSize;
}

// Erase element at idx if it equals val
int Array::operator()(int idx, int val) {
    if (idx < 0 || idx >= size) return -1;
    if (data[idx] != val) return -1;
    for (int i = idx; i < size - 1; i++)
        data[i] = data[i + 1];
    size--;
    return 1;
}

// Destructor
Array::~Array() {
    delete[] data;
    data = nullptr;
}

// Output operator
ostream& operator<<(ostream& output, const Array& arr) {
    output << "[";
    for (int i = 0; i < arr.size; i++) {
        output << arr.data[i];
        if (i < arr.size - 1) output << ", ";
    }
    output << "]";
    return output;
}

// Input operator
istream& operator>>(istream& input, Array& arr) {
    for (int i = 0; i < arr.size; i++)
        input >> arr.data[i];
    return input;
}

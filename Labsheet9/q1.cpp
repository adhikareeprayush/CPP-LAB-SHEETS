#include <iostream>
using namespace std;

// Template function to calculate the sum of array elements
template <typename T>
T sum(const T* arr, size_t size) {
    T total = 0;
    for (size_t i = 0; i < size; ++i) {
        total += arr[i];
    }
    return total;
}

int main() {
    // Integer array
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Sum of integer array: " << sum(intArr, intSize) << endl;

    // Float array
    float floatArr[] = {1.5f, 2.5f, 3.5f, 4.5f};
    size_t floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    cout << "Sum of float array: " << sum(floatArr, floatSize) << endl;

    // Double array
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    cout << "Sum of double array: " << sum(doubleArr, doubleSize) << endl;

    return 0;
}

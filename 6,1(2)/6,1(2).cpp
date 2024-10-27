// рукурсія
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateArray(int arr[], int size, int minValue, int maxValue) {
    for (int i = 0; i < size; i++) {
        arr[i] = minValue + rand() % (maxValue - minValue + 1);
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

void countAndSumRecursive(const int arr[], int size, int index, int& count, int& sum) {
    if (index >= size) {
        return;
    }
    if (arr[index] > 0 && arr[index] % 2 != 0) {
        count++;
        sum += arr[index];
    }
    countAndSumRecursive(arr, size, index + 1, count, sum);
}

void replaceWithZeroRecursive(int arr[], int size, int index) {
    if (index >= size) {
        return;
    }
    if (arr[index] > 0 && arr[index] % 2 != 0) {
        arr[index] = 0;
    }
    replaceWithZeroRecursive(arr, size, index + 1);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    const int size = 23;
    int arr[size];

    generateArray(arr, size, -25, 80);

    cout << " Start:        ";
    printArray(arr, size);

    int count = 0, sum = 0;
    countAndSumRecursive(arr, size, 0, count, sum);
    cout << " Satisfaction:   " << count << endl;
    cout << " Sum:            " << sum << endl;

    replaceWithZeroRecursive(arr, size, 0);

    cout << " Modification: ";
    printArray(arr, size);

    return 0;
}

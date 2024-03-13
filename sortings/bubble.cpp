#include <iostream>
#include <ctime>
#include <random>

using namespace std;

const size_t arr_size = 30;

void print_array(int *arr, size_t size) {
    cout << '[';
    for (size_t i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << ']'<<'\n';
}

void bubble_sort(int *arr, size_t size) {
    while(size>1) {
        for (size_t i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int cur = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = cur;
            }
        }
        size--;
    }
}

int main() {
    int *arr = new int[arr_size];

    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution dist(1, 100);

    for (size_t i = 0; i < arr_size; i++) {
        arr[i] = dist(eng);
    }
    print_array(arr, arr_size);
    bubble_sort(arr, arr_size);
    print_array(arr, arr_size);

    return 0;
}

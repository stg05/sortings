//
// Created by stg05 on 13.03.2024.
//

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
    cout << ']' << '\n';
}

void selection_sort(int *arr, size_t size) {
    while (size > 1) {
        int *max = arr;
        for (size_t i = 0; i < size; i++) {
            if (*(arr + i) > *max) {
                max = arr + i;
            }
        }
        int cur = *(arr + size - 1);
        *(arr + size - 1) = *max;
        *max = cur;
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
    selection_sort(arr, arr_size);
    print_array(arr, arr_size);

    return 0;
}

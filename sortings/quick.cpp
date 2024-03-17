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

void merge_sort(int *arr, size_t start, size_t end) {
    int idx_left = start - 1, idx_right = start - 1;
    while (true) {
        idx_right++;
        if (arr[idx_right] > arr[end]) {
            continue;
        } else {
            idx_left++;
            if (idx_right > idx_left) {
                swap(arr[idx_right], arr[idx_left]);
            }
        }
        if (idx_right >= end) break;
    }
    if (start != idx_left - 1) {
        if (idx_left > start) {
            merge_sort(arr, start, idx_left - 1);
        }
    }
    if (idx_left + 1 < end) {
        merge_sort(arr, idx_left + 1, end);
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
    merge_sort(arr, 0, arr_size - 1);
    print_array(arr, arr_size);

    return 0;
}

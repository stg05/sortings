//
// Created by stg05 on 17.03.2024.
//

#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

const size_t arr_size = 30;

void merge(int *arr, size_t left, size_t mid, size_t right) {
    auto res = new int[right - left];
    size_t ptr_l = left, ptr_r = mid, ptr = 0;
    while (true) {
        if (ptr_l == mid) {
            while (ptr_r < right) {
                res[ptr++] = arr[ptr_r++];
            }
            break;
        }
        if (ptr_r == right) {
            while (ptr_l < mid) {
                res[ptr++] = arr[ptr_l++];
            }
            break;
        }
        if (arr[ptr_r] > arr[ptr_l]) {
            res[ptr++] = arr[ptr_l++];
        } else {
            res[ptr++] = arr[ptr_r++];
        }
    }
    for (size_t i = 0; i < right - left; i++) {
        arr[left + i] = res[i];
    }
    delete[] res;
}

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
    size_t mid = (start + end) / 2;
    if (mid - start > 1) {
        merge_sort(arr, start, mid);
    }
    if (end - mid > 1) {
        merge_sort(arr, mid, end);
    }
    merge(arr, start, mid, end);
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
    merge_sort(arr, 0, arr_size);
    print_array(arr, arr_size);

    return 0;
}

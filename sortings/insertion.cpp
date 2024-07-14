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
    cout << ']'<<'\n';
}

void insertion_sort(int *arr, size_t size) {
    for(size_t sorted = 1; sorted<size; sorted++){
        size_t ptr = sorted-1;
        while(true){
            if(arr[ptr]<arr[sorted]){
                break;
            }
            ptr--;
            if(ptr == -1) break;
        }

        int cur = arr[sorted];
        for(size_t j = sorted; j>ptr+1; j--){
            arr[j] = arr[j-1];
        }
        arr[ptr+1] = cur;
    }

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
    insertion_sort(arr, arr_size);
    print_array(arr, arr_size);

    return 0;
}

#include "heap_sort.hpp"
#include <iostream>

HeapSort::HeapSort(const int* arr, int sz) : n{ sz } {
    array = new int[ n ];
    for(int i{ 0 }; i != n; ++i) {
        array[i] = arr[i];
    }
    sort();
}

void HeapSort::build_heap() {
    for(int i{ n / 2 - 1 }; i >= 0; --i) {
        heapify(array, n, i);
    }
}

void HeapSort::sort() {
    build_heap();
    for(int i{ n - 1 }; i >= 0; --i) {
        swap(array, 0, i);
        heapify(array, i, 0);
    }
}

void heapify(int* array, int n, int root) {
    int max{ root };
    int l{ 2 * max + 1 }, r{ 2 * root + 2 };

    if(l < n && array[l] > array[max]) {
        max = l;
    }

    if(r < n && array[r] > array[max]) {
        max = r;
    }

    if(max != root) {
        swap(array, root, max);
        heapify(array, n, max);
    }
}

void swap(int* array, int k, int m) {
    int tmp{ array[k] };
    array[k] = array[m];
    array[m] = tmp;
}

void display(int* array, int n) {
    for(int i{ 0 }; i != n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}
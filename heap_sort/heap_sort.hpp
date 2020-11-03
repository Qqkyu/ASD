#pragma once
#include <algorithm>

class HeapSort {
public:
    HeapSort(const int* arr, int sz);
    ~HeapSort() { delete[] array; }

    bool is_sorted() { return std::is_sorted(array, array + n); }
private:
    int* array;
    int n;

    void build_heap();
    void sort();
};

void heapify(int* array, int n, int root);
void swap(int* array, int k, int m);

void display(int* array, int n);
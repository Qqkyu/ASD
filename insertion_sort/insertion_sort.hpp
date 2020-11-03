#pragma once
#include <initializer_list>
#include <algorithm>

class Insertion_sort {
public:
    Insertion_sort(std::initializer_list<int>);
    Insertion_sort(const int* arr, size_t sz);

    ~Insertion_sort();

    void print() const;
    bool is_sorted() const { return std::is_sorted(array, array + size); }
private:
    size_t size;
    int* array;

    void sort();
};

#include "insertion_sort.hpp"
#include <iostream>

Insertion_sort::Insertion_sort(std::initializer_list<int> li)
    : size{ li.size() }, array{ new int[size] }
{
    size_t i{ 0 };
    for(auto x : li) {
        array[i++] = x;
    }
    sort();
}

Insertion_sort::Insertion_sort(const int* arr, size_t sz)
    : size{ sz }, array{ new int[size] }
{
    for(size_t i{ 0 }; i != size; ++i) {
        array[i] = arr[i];
    }
    sort();
}

Insertion_sort::~Insertion_sort() {
    delete[] array;
}

void Insertion_sort::print() const {
    for(size_t i{ 0 }; i != size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

void Insertion_sort::sort() {
    for(int j{ 1 }; j < size; ++j) {
        int elem{ array[j] };
        int i{ j - 1 };
        while(i >= 0 && array[i] > elem) {
            array[i + 1] = array[i];
            --i;
        }
        array[i + 1] = elem;
    }
}

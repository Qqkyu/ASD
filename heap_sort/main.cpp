#include "heap_sort.hpp"
#include <iostream>
#include <random>
#include <climits>

int main() {
    int size{ 100000 };
    int arr[size];

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(INT_MIN,INT_MAX);

    for(auto k{ 0u }; k != 100; ++k) {
        for (auto i{0u}; i != size; ++i) {
            arr[i] = dist(rng);
        }
        HeapSort is{arr, size};
        std::cout << (is.is_sorted() ? "Correct!" : "Not correct!") << std::endl;
    }
    return 0;
}
#include <iostream>
#include <random>
#include <climits>
#include <algorithm>

void sort(int*, int);
void mergeSort(int*, int*, int, int);
void merge(int*, int*, int, int, int);

int main()
{
    const int size{ 100000 };
    int arr[size];

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1000000);

    for (auto k{ 0u }; k != 100; ++k) {
        for (auto i{ 0u }; i != size; ++i) {
            arr[i] = dist(rng);
        }
        sort(arr, size);
        std::cout << (std::is_sorted(arr, arr + size) ? "Correct!" : "Not correct!") << std::endl;
    }
    return 0;
}

void sort(int* arr, int n) {
    int* auxArr{ new int[n] };
    mergeSort(arr, auxArr, 0, n - 1);
    delete[] auxArr;
}

void mergeSort(int* arr, int* auxArr, int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int m{ (leftIndex + rightIndex) / 2 };
        mergeSort(arr, auxArr, leftIndex, m);
        mergeSort(arr, auxArr, m + 1, rightIndex);
        merge(arr, auxArr, leftIndex, m, rightIndex);
    }
}

void merge(int* arr, int* auxArr, int leftIndex, int m, int rightIndex) {
    for (int i{ leftIndex }; i <= rightIndex; ++i)
        auxArr[i] = arr[i];

    int k{ leftIndex }, j{ m + 1 }, cur{ leftIndex };
    while (k <= m && j <= rightIndex) {
        if (auxArr[k] <= auxArr[j]) {
            arr[cur] = auxArr[k];
            ++k;
        }
        else {
            arr[cur] = auxArr[j];
            ++j;
        }
        ++cur;
    }
    while (k <= m) {
        arr[cur] = auxArr[k];
        ++cur;
        ++k;
    }
}

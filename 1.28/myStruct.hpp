#pragma once
#include <stack>

class Struct {
public:
    explicit Struct(int range);
    ~Struct() { delete[] arr; }

    void select();
    bool search(int x) const;
    void insert(int x);
private:
    int n;
    int* arr;
    std::stack<int> elems;
};


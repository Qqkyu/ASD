#pragma once
#include <vector>
#include <deque>

class myStruct {
public:
    explicit myStruct(int n) : mainList(n), indices(n) { }

    void push(int);
    void pop();
    bool search(int);
    void delete_(int);
private:
    std::deque<int> mainList;
    std::vector<std::deque<int>> indices;
    int length{ 0 };
};

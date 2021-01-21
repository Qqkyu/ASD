#include "myStruct.hpp"

void myStruct::push(int x) {
    mainList.push_back(x);
    indices[x].push_front(length++);
}

void myStruct::pop() {
    auto x = *mainList.begin();
    mainList.pop_front();
    indices[x].pop_front();
}

bool myStruct::search(int x) {
    return indices[x].empty();
}

void myStruct::delete_(int x) {
    while(!indices[x].empty()) {
        auto elemIndex = indices[x].front();
        indices[x].pop_front();
        mainList.erase(mainList.begin() + elemIndex);
        indices[x].pop_front();
    }
}
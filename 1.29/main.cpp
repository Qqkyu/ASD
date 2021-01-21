#include <iostream>
#include "cmake-build-debug/myStruct.hpp"

int main() {
    myStruct a(30);
    a.push(10);
    a.pop();
    for(auto i{ 0u }; i != 10; ++i) {
        a.push(i);
    }
    a.search(9);
    a.delete_(1);
    return 0;
}

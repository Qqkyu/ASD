#include <iostream>
#include "myStruct.hpp"

int main() {
    // Example:
    Struct s{ 10 };
    s.select();
    std::cout << s.search(4) << '\n';
    s.insert(0);
    s.insert(1);
    s.insert(10);
    std::cout << s.search(0) << '\n';
    std::cout << s.search(1) << '\n';
    std::cout << s.search(10) << '\n';
    s.select();
    std::cout << s.search(10) << '\n';
    s.select();
    std::cout << s.search(1) << '\n';
    s.select();
    return 0;
}

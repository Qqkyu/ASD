#include "RBT.hpp"
#include <iostream>

int main() {
    RBT bst;
    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);
    bst.printInorder();
    std::cout << "\n";
    bst.remove(40);
    bst.printInorder();
    std::cout << "\n";
    bst.remove(55);
    bst.printInorder();
    std::cout << "\n";
    bst.remove(60);
    bst.printInorder();
    std::cout << "\n";
    bst.remove(65);
    bst.printInorder();
    std::cout << "\n";
    bst.remove(75);
    bst.printInorder();
    std::cout << "\n";
    bst.remove(57);
    bst.printInorder();
    std::cout << "\n";
    return 0;
}

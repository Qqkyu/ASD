#include "BST.hpp"
#include <vector>

int main() {
    BST bst;
    std::vector<int> vi{100,55,50,45,47,70,80,78,77,79,82,81,83,150,140,135,142,143,180,170,165,160,175,173,200,190,195,500,1000,1500,2000,3000,4000,5000,6000,7000,8000,9000};
    for(auto x : vi) {
        bst.insert(x);
    }
    bst.printPreorder();
    std::cout << '\n';
    bst.printInorder();
    std::cout << '\n';
    bst.printPostorder();
    std::cout << '\n';
    for(int i{ static_cast<int>(vi.size()) - 1 }; i >= 0; --i) {
        bst.remove(vi[i]);
    }
    bst.printInorder();

    return 0;
}

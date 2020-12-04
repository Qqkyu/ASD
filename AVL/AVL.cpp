#include "AVL.hpp"
#include <algorithm>
#include <iostream>

int AVL::height(const node* cur) const {
    int h{ 0 };
    if(cur) {
        int l_height{ height(cur->left) };
        int r_height{ height(cur->right) };
        int max_height(std::max(l_height, r_height));
        h = max_height + 1;
    }
    return h;
}

int AVL::difference(const node* cur) const {
    int l_height{ height(cur->left) };
    int r_height{ height(cur->right) };
    int b_factor{ l_height - r_height };
    return b_factor;
}

AVL::node* AVL::rightRotation(node* parent) {
    if(!parent->left) {
        return parent;
    }
    node* u{ parent->left };
    parent->left = u->right;
    u->right = parent;
    return u;
}

AVL::node* AVL::leftRotation(node* parent) {
    if(!parent->right) {
        return parent;
    }
    node* u{ parent->right };
    parent->right = u->left;
    u->left = parent;
    return u;
}

AVL::node* AVL::leftRightRotation(node* parent) {
    parent->left = leftRotation(parent->left);
    return rightRotation(parent);
}

AVL::node* AVL::rightLeftRotation(node* parent) {
    parent->right = rightRotation(parent->right);
    return leftRotation(parent);
}

AVL::node* AVL::insert(node* cur, int x) {
    if(!cur) {
        cur = new node{ x, nullptr, nullptr };
        return cur;
    }
    else if(x < cur->data) {
        cur->left = insert(cur->left, x);
        if(height(cur->left) - height(cur->right) == 2) {
            if(x < cur->left->data) {
                cur = rightRotation(cur);
            }
            else {
                cur = leftRightRotation(cur);
            }
        }
    }
    else if(x > cur->data) {
        cur->right = insert(cur->right, x);
        if(height(cur->right) - height(cur->left) == 2) {
            if(x > cur->right->data) {
                cur = leftRotation(cur);
            }
            else {
                cur = rightLeftRotation(cur);
            }
        }
    }
    return cur;
}

AVL::node* AVL::remove(node* cur, int x) {
    if(!cur)
        return nullptr;

    if(cur->data > x) {
        cur->left = remove(cur->left, x);
    }
    else if(cur->data < x) {
        cur->right = remove(cur->right, x);
    }

    if(cur->left && cur->right) {
        node* tmp{ min(cur->right) };
        cur->data = tmp->data;
        cur->right = remove(cur->right, cur->data);
    }
    else {
        node* tmp{ cur };
        if(!cur->left) {
            cur = cur->right;
        }
        else if(!cur->right) {
            cur = cur->left;
        }
        delete tmp;
    }
    if(!cur) {
        return cur;
    }

    if (cur->right && (height(cur->left) - height(cur->right) == 2)) {
        if (height(cur->right->right) - height(cur->right->left) == 1) {
            return leftRotation(cur);
        } else {
            return rightLeftRotation(cur);
        }
    }
    else if (cur->left && (height(cur->right) - height(cur->left) == 2)) {
        if (height(cur->left->left) - height(cur->left->right) == 1) {
            return rightRotation(cur);
        } else {
            return leftRightRotation(cur);
        }
    }
    return cur;
}

void AVL::printPreorder(const node* cur) const {
    std::cout << cur->data << " ";
    if(cur->left) {
        printPreorder(cur->left);
    }
    if(cur->right) {
        printPreorder(cur->right);
    }
}

void AVL::printInorder(const node* cur) const {
    if(cur->left) {
        printInorder(cur->left);
    }
    std::cout << cur->data << " ";
    if(cur->right) {
        printInorder(cur->right);
    }
}

void AVL::printPostorder(const node* cur) const {
    if(cur->left) {
        printPostorder(cur->left);
    }
    if(cur->right) {
        printPostorder(cur->right);
    }
    std::cout << cur->data << " ";
}

AVL::node* AVL::min(node* cur) const {
    if(!cur)
        return nullptr;

    return (cur->left) ? min(cur->left) : cur;
}

AVL::node* AVL::max(node* cur) const {
    if(!cur)
        return nullptr;

    return (cur->right) ? max(cur->right) : cur;
}
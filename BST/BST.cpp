#include "BST.hpp"
#include <iostream>

BST::node* BST::insert(node* cur, int value) {
    if(cur == nullptr) {
        return new node(value);
    }
    if(value < cur->data)
        cur->left = insert(cur->left, value);
    else
        cur->right = insert(cur->right, value);

    return cur;
}

BST::node* BST::inorderSucc(node* node) {
    BST::node* cur{ node };
    while(cur && cur->left) {
        cur = cur->left;
    }
    return cur;
}

BST::node* BST::remove(node* root, int value) {
    if(root == nullptr) {
        return root;
    }

    if(value < root->data) {
        root->left = remove(root->left, value);
    }
    else if(value > root->data) {
        root->right = remove(root->right, value);
    }
    else {
        if(root->left == nullptr) {
            node* temp{ root->right };
            delete root;
            return temp;
        }
        else if(root->right == nullptr) {
            node* temp{ root->left };
            delete root;
            return temp;
        }
        node* temp{ inorderSucc(root->right) };
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    return root;
}

bool BST::contains(const BST::node* cur, int value) {
    if(value == cur->data) {
        return true;
    }
    else if(value < cur->data) {
        if(cur->left) {
            return contains(cur->left, value);
        }
        else {
            return false;
        }
    }
    else {
        if(cur->right) {
            return contains(cur->right, value);
        }
        return false;
    }
}

void BST::printPreorder(const node* cur) {
    std::cout << cur->data << " ";
    if(cur->left) {
        printPreorder(cur->left);
    }
    if(cur->right) {
        printPreorder(cur->right);
    }
}

void BST::printInorder(const node* cur) {
    if(cur->left) {
        printInorder(cur->left);
    }
    std::cout << cur->data << " ";
    if(cur->right) {
        printInorder(cur->right);
    }
}

void BST::printPostorder(const node* root) {
    if(root->left) {
        printPostorder(root->left);
    }
    if(root->right) {
        printPostorder(root->right);
    }
    std::cout << root->data << " ";
}

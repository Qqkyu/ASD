#pragma once
#include <iostream>

class BST {
public:
    BST() = default;

    void insert(int x) { root = insert(root, x); }
    void remove(int x) { root = remove(root, x); }

    bool contains(int x) { return contains(root, x); }

    void printPreorder() { if(root) printPreorder(root); }
    void printInorder() { if(root) printInorder(root); }
    void printPostorder() { if(root) printPostorder(root); }

private:

    struct node {
        int data;
        node* left;
        node* right;

        explicit node(int x) : data{ x }, left{ nullptr }, right{ nullptr } { }
    };

    node* root{ };

    node* insert(node*, int);
    node* remove(node*, int);

    bool contains(const node*, int);

    void printPreorder(const node*);
    void printInorder(const node*);
    void printPostorder(const node*);

//Auxiliary:
    node* inorderSucc(node*);
};

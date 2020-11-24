#pragma once
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int x) : data{ x }, left{ nullptr }, right{ nullptr } { }
};

Node* insert(Node*, int);
Node* remove(Node*, int);
bool contains(const Node*, int);
void printPreOrder(const Node*, std::ostream&);
void printInOrder(const Node*, std::ostream&);
void printPostOrder(const Node*, std::ostream&);

//Auxiliary:
Node* inorderSucc(Node*);

class BST {
public:
    explicit BST(int data) : root{ new Node(data) } { }

    void insert(int x) {
        root = ::insert(root, x);
    }
    void remove(int x) {
        root = ::remove(root, x);
    }
    bool contains(int x) {
        return ::contains(root, x);
    }
    void printPreOrder(std::ostream& os) {
        ::printPreOrder(root, os);
    }
    void printInOrder(std::ostream& os) {
        ::printInOrder(root, os);
    }
    void printPostOrder(std::ostream& os) {
        ::printPostOrder(root, os);
    }

private:
    Node* root;
};

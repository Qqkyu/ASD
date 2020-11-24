#pragma once
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int x) : data{ x }, left{ nullptr }, right{ nullptr } { }
};

int height(const Node*);
int difference(const Node*);
Node* rr_rot(Node*);
Node* ll_rot(Node*);
Node* lr_rot(Node*);
Node* rl_rot(Node*);
Node* balance(Node*);

Node* insert(Node*, int);
Node* remove(Node*, int);
bool contains(const Node*, int);
void printPreOrder(const Node*, std::ostream&);
void printInOrder(const Node*, std::ostream&);
void printPostOrder(const Node*, std::ostream&);

class AVL {
public:
    explicit AVL(int data) : root{ new Node(data) } { }

    void insert(int x) {
        root = ::insert(root, x);
    }
    void remove(int x) {
        root = ::remove(root, x);
        root = balance(root);
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

#pragma once

class AVL {
public:
    AVL() = default;

    void insert(int x) { root = insert(root, x); }
    void remove(int x) { root = remove(root, x); }

    void printPreorder() const { if(root) printPreorder(root); }
    void printInorder() const { if(root) printInorder(root); }
    void printPostorder() const { if(root) printPostorder(root); }
private:

    struct node {
        int data;
        node* left;
        node* right;
    };

    int height(const node*) const;
    int difference(const node*) const;

    node* rightRotation(node*);
    node* leftRotation(node*);
    node* leftRightRotation(node*);
    node* rightLeftRotation(node*);

    node* insert(node*, int);
    node* remove(node*, int);

    void printPreorder(const node*) const;
    void printInorder(const node*) const;
    void printPostorder(const node*) const;

    node* min(node*) const;
    node* max(node*) const;

    node* root{ nullptr };
};
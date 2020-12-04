#pragma once

class RBT {
public:
    RBT();

    void insert(int x);
    void remove(int x);

    void printPreorder() const { if(root != tnull) printPreorder(root); }
    void printInorder() const { if(root != tnull) printInorder(root); }
    void printPostorder() const { if(root != tnull) printPostorder(root); }
private:
    enum class color{red, black};

    struct node {
        int data;
        color clr;
        node* left;
        node* right;
        node* parent;

        explicit node(int x = 0, node* _parent = nullptr) :
            data{ x }, clr{ color::black }, parent{ _parent }
        {
            left = right = nullptr;
        }
    };

    void printPreorder(const node*) const;
    void printInorder(const node*) const;
    void printPostorder(const node*) const;

    node* searchTreeHelper(node*, int);
    void deleteFix(node*);
    void insertFix(node*);
    void rbTransplant(node*, node*);
    void deleteNodeHelper(node*, int);

    void leftRotate(node*);
    void rightRotate(node*);

    node* min(node*);

    node* tnull;
    node* root;
};

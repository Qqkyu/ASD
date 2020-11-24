#include "BST.hpp"

Node* insert(Node* root, int value) {
    if(root == nullptr) {
        return new Node(value);
    }
    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

Node* inorderSucc(Node* node) {
    Node* cur{ node };
    while(cur && cur->left) {
        cur = cur->left;
    }
    return cur;
}

Node* remove(Node* root, int value) {
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
            Node* temp{ root->right };
            delete root;
            return temp;
        }
        else if(root->right == nullptr) {
            Node* temp{ root->left };
            delete root;
            return temp;
        }
        Node* temp{ inorderSucc(root->right) };
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    return root;
}

bool contains(const Node* root, int value) {
    if(value == root->data) {
        return true;
    }
    else if(value < root->data) {
        if(root->left) {
            return contains(root->left, value);
        }
        else {
            return false;
        }
    }
    else {
        if(root->right) {
            return contains(root->right, value);
        }
        return false;
    }
}

void printPreOrder(const Node* root, std::ostream& os) {
    os << root->data << " ";
    if(root->left) {
        printPreOrder(root->left, os);
    }
    if(root->right) {
        printPreOrder(root->right, os);
    }
}

void printInOrder(const Node* root, std::ostream& os) {
    if(root->left) {
        printInOrder(root->left, os);
    }
    os << root->data << " ";
    if(root->right) {
        printInOrder(root->right, os);
    }
}

void printPostOrder(const Node* root, std::ostream& os) {
    if(root->left) {
        printPostOrder(root->left, os);
    }
    if(root->right) {
        printPostOrder(root->right, os);
    }
    os << root->data << " ";
}

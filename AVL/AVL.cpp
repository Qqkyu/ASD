#include "AVL.hpp"

Node* inorderSucc(Node* node) {
    Node* cur{ node };
    while(cur && cur->left) {
        cur = cur->left;
    }
    return cur;
}

int height(const Node* root) {
    int h{ 0 };
    if(root) {
        int l_height{ height(root->left) };
        int r_height{ height(root->right) };
        int max_height = std::max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int difference(const Node* root) {
    int l_height = height(root->left);
    int r_height = height(root->right);
    return (l_height - r_height);
}

Node* rr_rot(Node* parent) {
    Node* t{ parent->right };
    parent->right = t->left;
    t->left = parent;
    return t;
}

Node* ll_rot(Node* parent) {
    Node* t{ parent->left };
    parent->left = t->right;
    t->right = parent;
    return t;
}

Node* lr_rot(Node* parent) {
    Node* t{ parent->left };
    parent->left = rr_rot(t);
    return ll_rot(parent);
}

Node* rl_rot(Node* parent) {
    Node* t{ parent->right };
    parent->right = ll_rot(t);
    return rr_rot(parent);
}

Node* balance(Node* root) {
    int b_factor{ difference(root) };
    if(b_factor > 1) {
        if(difference(root->left) > 0) {
            root = ll_rot(root);
        }
        else {
            root = lr_rot(root);
        }
    }
    else if(b_factor < -1) {
        if(difference(root->right) > 0) {
            root = rl_rot(root);
        }
        else {
            root = rr_rot(root);
        }
    }
    return root;
}

Node* insert(Node* root, int v) {
    if(root == nullptr) {
        root = new Node{ v };
        root->left = root->right = nullptr;
        return root;
    }
    else if(v < root->data) {
        root->left = insert(root->left, v);
        root = balance(root);
    }
    else if(v >= root->data) {
        root->right = insert(root->right, v);
        root = balance(root);
    }
    return root;
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
#include "RBT.hpp"
#include <iostream>

RBT::RBT() {
    tnull = new node{ };
    root = tnull;
}

void RBT::insert(int key) {
    node* n{ new node{ key } };
    n->left = n->right = tnull;
    node* y{ nullptr }, *x{ root };

    while(x != tnull) {
        y = x;
        if(n->data < x->data) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    n->parent = y;
    if(y == nullptr) {
        root = n;
    }
    else if(n->data < y->data) {
        y->left = n;
    }
    else {
        y->right = n;
    }

    if(n->parent == nullptr) {
        n->clr = color::black;
        return;
    }

    if(n->parent->parent == nullptr) {
        return;
    }
    insertFix(n);
}

void RBT::remove(int x) {
    deleteNodeHelper(root, x);
}

void RBT::printPreorder(const node* cur) const {
    std::cout << cur->data << " ";
    if(cur->left != tnull) {
        printPreorder(cur->left);
    }
    if(cur->right != tnull) {
        printPreorder(cur->right);
    }
}

void RBT::printInorder(const node* cur) const {
    if(cur->left != tnull) {
        printInorder(cur->left);
    }
    std::cout << cur->data << " ";
    if(cur->right != tnull) {
        printInorder(cur->right);
    }
}

void RBT::printPostorder(const node* cur) const {
    if(cur->left != tnull) {
        printPostorder(cur->left);
    }
    if(cur->right != tnull) {
        printPostorder(cur->right);
    }
    std::cout << cur->data << " ";
}

RBT::node* RBT::searchTreeHelper(node* cur, int key) {
    if(cur == tnull || key == cur->data) {
        return cur;
    }
    return (key < cur->data) ? searchTreeHelper(cur->left, key) : searchTreeHelper(cur->right, key);
}

void RBT::deleteFix(node* n) {
    node* s;
    while(n != root && n->clr == color::black) {
        if(n == n->parent->left) {
            s = n->parent->right;
            if(s->clr == color::red) {
                s->clr = color::black;
                n->parent->clr = color::red;
                leftRotate(n->parent);
                s = n->parent->right;
            }

            if(s->left->clr == color::black && s->right->clr == color::black) {
                s->clr = color::red;
                n = n->parent;
            }
            else {
                if(s->right->clr == color::black) {
                    s->left->clr = color::black;
                    s->clr = color::red;
                    rightRotate(s);
                    s = n->parent->right;
                }

                s->clr = n->parent->clr;
                n->parent->clr = color::black;
                s->right->clr = color::black;
                leftRotate(n->parent);
                n = root;
            }
        }
        else {
            s = n->parent->left;
            if(s->clr == color::red) {
                s->clr = color::black;
                n->parent->clr = color::red;
                rightRotate(n->parent);
                s = n->parent->left;
            }
            if(s->left->clr == color::black && s->right->clr == color::black) {
                s->clr = color:: red;
                n = n->parent;
            }
            else {
                if(s->left->clr == color::black) {
                    s->right->clr = color::black;
                    s->clr = color::red;
                    leftRotate(s);
                    s = n->parent->left;
                }

                s->clr = n->parent->clr;
                n->parent->clr = color::black;
                s->left->clr = color::black;
                rightRotate(n->parent);
                n = root;
            }
        }
    }
    n->clr = color::black;
}

void RBT::rbTransplant(node* u, node* v) {
    if(u->parent == nullptr) {
        root = v;
    }
    else if(u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RBT::deleteNodeHelper(node* n, int key) {
    node* z = tnull;
    node* x, *y;
    while (n != tnull) {
        if (n->data == key) {
            z = n;
        }

        if (n->data <= key) {
            n = n->right;
        }
        else {
            n = n->left;
        }
    }

    if (z == tnull) {
        return;
    }

    y = z;
    color y_original_color = y->clr;
    if (z->left == tnull) {
        x = z->right;
        rbTransplant(z, z->right);
    }
    else if (z->right == tnull) {
        x = z->left;
        rbTransplant(z, z->left);
    }
    else {
        y = min(z->right);
        y_original_color = y->clr;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        }
        else {
            rbTransplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rbTransplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->clr = z->clr;
    }
    delete z;
    if (y_original_color == color::black) {
        deleteFix(x);
    }
}

void RBT::insertFix(node* k) {
    node* u;
    while (k->parent->clr == color::red) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->clr == color::red) {
                u->clr = color::black;
                k->parent->clr = color::black;
                k->parent->parent->clr = color::red;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(k);
                }
                k->parent->clr = color::black;
                k->parent->parent->clr = color::red;
                leftRotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;

            if (u->clr == color::red) {
                u->clr = color::black;
                k->parent->clr = color::black;
                k->parent->parent->clr = color::red;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(k);
                }
                k->parent->clr = color::black;
                k->parent->parent->clr = color::red;
                rightRotate(k->parent->parent);
            }
        }
        if (k == root) {
            break;
        }
    }
    root->clr = color::black;
}

void RBT::leftRotate(node* x) {
    node* y = x->right;
    x->right = y->left;
    if (y->left != tnull) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RBT::rightRotate(node* x) {
    node* y = x->left;
    x->left = y->right;
    if (y->right != tnull) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

RBT::node* RBT::min(node* cur) {
    while(cur->left != tnull) {
        cur = cur->left;
    }
    return cur;
}
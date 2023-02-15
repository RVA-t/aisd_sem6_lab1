#include "bst.h"
using namespace std;

struct NodeRBT {
    int data;
    NodeRBT* parent;
    NodeRBT* left;
    NodeRBT* right;
    int color;
};

typedef NodeRBT* NodeRBTPtr;

class RedBlackTree {
private:
    NodeRBTPtr root;
    NodeRBTPtr TNULL;

    void initializeNULLNodeRBT(NodeRBTPtr NodeRBT, NodeRBTPtr parent) {
        NodeRBT->data = 0;
        NodeRBT->parent = parent;
        NodeRBT->left = nullptr;
        NodeRBT->right = nullptr;
        NodeRBT->color = 0;
    }

    void preOrderHelper(NodeRBTPtr NodeRBT) {
        if (NodeRBT != TNULL) {
            cout << NodeRBT->data << " ";
            preOrderHelper(NodeRBT->left);
            preOrderHelper(NodeRBT->right);
        }
    }

    void inOrderHelper(NodeRBTPtr NodeRBT) {
        if (NodeRBT != TNULL) {
            inOrderHelper(NodeRBT->left);
            cout << NodeRBT->data << " ";
            inOrderHelper(NodeRBT->right);
        }
    }

    void postOrderHelper(NodeRBTPtr NodeRBT) {
        if (NodeRBT != TNULL) {
            postOrderHelper(NodeRBT->left);
            postOrderHelper(NodeRBT->right);
            cout << NodeRBT->data << " ";
        }
    }

    NodeRBTPtr searchTreeHelper(NodeRBTPtr NodeRBT, int key) {
        if (NodeRBT == TNULL || key == NodeRBT->data) {
            return NodeRBT;
        }

        if (key < NodeRBT->data) {
            return searchTreeHelper(NodeRBT->left, key);
        }
        return searchTreeHelper(NodeRBT->right, key);
    }

    void deleteFix(NodeRBTPtr x) {
        NodeRBTPtr s;
        while (x != root && x->color == 0) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == 1) {
                    s->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == 0 && s->right->color == 0) {
                    s->color = 1;
                    x = x->parent;
                }
                else {
                    if (s->right->color == 0) {
                        s->left->color = 0;
                        s->color = 1;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->right->color = 0;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else {
                s = x->parent->left;
                if (s->color == 1) {
                    s->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == 0 && s->right->color == 0) {
                    s->color = 1;
                    x = x->parent;
                }
                else {
                    if (s->left->color == 0) {
                        s->right->color = 0;
                        s->color = 1;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = 0;
    }

    void rbTransplant(NodeRBTPtr u, NodeRBTPtr v) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void deleteNodeRBTHelper(NodeRBTPtr NodeRBT, int key) {
        NodeRBTPtr z = TNULL;
        NodeRBTPtr x, y;
        while (NodeRBT != TNULL) {
            if (NodeRBT->data == key) {
                z = NodeRBT;
            }

            if (NodeRBT->data <= key) {
                NodeRBT = NodeRBT->right;
            }
            else {
                NodeRBT = NodeRBT->left;
            }
        }

        if (z == TNULL) {
            cout << "Key not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
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
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) {
            deleteFix(x);
        }
    }

    void insertFix(NodeRBTPtr k) {
        NodeRBTPtr u;
        while (k->parent->color == 1) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    leftRotate(k->parent->parent);
                }
            }
            else {
                u = k->parent->parent->right;

                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = 0;
    }

    void printHelper(NodeRBTPtr root, string indent, bool last) {
        if (root != TNULL) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "   ";
            }
            else {
                cout << "L----";
                indent += "|  ";
            }

            string sColor = root->color ? "RED" : "BLACK";
            cout << root->data << "(" << sColor << ")" << endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

public:
    RedBlackTree() {
        TNULL = new NodeRBT;
        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }

    void preorder() {
        preOrderHelper(this->root);
    }

    void inorder() {
        inOrderHelper(this->root);
    }

    void postorder() {
        postOrderHelper(this->root);
    }

    NodeRBTPtr searchTree(int k) {
        return searchTreeHelper(this->root, k);
    }

    NodeRBTPtr minimum(NodeRBTPtr NodeRBT) {
        while (NodeRBT->left != TNULL) {
            NodeRBT = NodeRBT->left;
        }
        return NodeRBT;
    }

    NodeRBTPtr maximum(NodeRBTPtr NodeRBT) {
        while (NodeRBT->right != TNULL) {
            NodeRBT = NodeRBT->right;
        }
        return NodeRBT;
    }

    NodeRBTPtr successor(NodeRBTPtr x) {
        if (x->right != TNULL) {
            return minimum(x->right);
        }

        NodeRBTPtr y = x->parent;
        while (y != TNULL && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    NodeRBTPtr predecessor(NodeRBTPtr x) {
        if (x->left != TNULL) {
            return maximum(x->left);
        }

        NodeRBTPtr y = x->parent;
        while (y != TNULL && x == y->left) {
            x = y;
            y = y->parent;
        }

        return y;
    }

    void leftRotate(NodeRBTPtr x) {
        NodeRBTPtr y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(NodeRBTPtr x) {
        NodeRBTPtr y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void insert(int key) {
        NodeRBTPtr Node = new NodeRBT;
        Node->parent = nullptr;
        Node->data = key;
        Node->left = TNULL;
        Node->right = TNULL;
        Node->color = 1;

        NodeRBTPtr y = nullptr;
        NodeRBTPtr x = this->root;

        while (x != TNULL) {
            y = x;
            if (Node->data < x->data) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        Node->parent = y;
        if (y == nullptr) {
            root = Node;
        }
        else if (Node->data < y->data) {
            y->left = Node;
        }
        else {
            y->right = Node;
        }

        if (Node->parent == nullptr) {
            Node->color = 0;
            return;
        }

        if (Node->parent->parent == nullptr) {
            return;
        }

        insertFix(Node);
    }

    NodeRBTPtr getRoot() {
        return this->root;
    }

    void deleteNodeRBT(int data) {
        deleteNodeRBTHelper(this->root, data);
    }

    void printTree() {
        if (root) {
            printHelper(this->root, "", true);
        }
    }
};
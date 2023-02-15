#include "rbt.h"

class NodeAVL {
public:
    int key;
    NodeAVL* left;
    NodeAVL* right;
    int height;
};

int max(int a, int b);

int height(NodeAVL* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

NodeAVL* newNodeAVL(int key) {
    NodeAVL* Node = new NodeAVL();
    Node->key = key;
    Node->left = NULL;
    Node->right = NULL;
    Node->height = 1;
    return (Node);
}

NodeAVL* rightRotate(NodeAVL* y) {
    NodeAVL* x = y->left;
    NodeAVL* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),
        height(y->right)) +
        1;
    x->height = max(height(x->left),
        height(x->right)) +
        1;
    return x;
}

NodeAVL* leftRotate(NodeAVL* x) {
    NodeAVL* y = x->right;
    NodeAVL* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),
        height(x->right)) +
        1;
    y->height = max(height(y->left),
        height(y->right)) +
        1;
    return y;
}

int getBalanceFactor(NodeAVL* N) {
    if (N == NULL)
        return 0;
    return height(N->left) -
        height(N->right);
}

NodeAVL* insertNode(NodeAVL* NodeAVL, int key) {
    if (NodeAVL == NULL)
        return (newNodeAVL(key));
    if (key < NodeAVL->key)
        NodeAVL->left = insertNode(NodeAVL->left, key);
    else if (key > NodeAVL->key)
        NodeAVL->right = insertNode(NodeAVL->right, key);
    else
        return NodeAVL;

    NodeAVL->height = 1 + max(height(NodeAVL->left),
        height(NodeAVL->right));
    int balanceFactor = getBalanceFactor(NodeAVL);
    if (balanceFactor > 1) {
        if (key < NodeAVL->left->key) {
            return rightRotate(NodeAVL);
        }
        else if (key > NodeAVL->left->key) {
            NodeAVL->left = leftRotate(NodeAVL->left);
            return rightRotate(NodeAVL);
        }
    }
    if (balanceFactor < -1) {
        if (key > NodeAVL->right->key) {
            return leftRotate(NodeAVL);
        }
        else if (key < NodeAVL->right->key) {
            NodeAVL->right = rightRotate(NodeAVL->right);
            return leftRotate(NodeAVL);
        }
    }
    return NodeAVL;
}

NodeAVL* NodeAVLWithMimumValue(NodeAVL* Node) {
    NodeAVL* current = Node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

NodeAVL* deleteNodeAVL(NodeAVL* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNodeAVL(root->left, key);
    else if (key > root->key)
        root->right = deleteNodeAVL(root->right, key);
    else {
        if ((root->left == NULL) ||
            (root->right == NULL)) {
            NodeAVL* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else {
            NodeAVL* temp = NodeAVLWithMimumValue(root->right);
            root->key = temp->key;
            root->right = deleteNodeAVL(root->right,
                temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
        height(root->right));
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
        if (getBalanceFactor(root->left) >= 0) {
            return rightRotate(root);
        }
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balanceFactor < -1) {
        if (getBalanceFactor(root->right) <= 0) {
            return leftRotate(root);
        }
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

void printTree(NodeAVL* root, string indent, bool last) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        }
        else {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->key << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

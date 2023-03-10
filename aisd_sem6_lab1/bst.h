#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

auto start = chrono::steady_clock::now();
auto end = chrono::steady_clock::now();

class NodeBST {
public:
    int key;
    struct NodeBST* left, * right;
};

NodeBST* newNodeBST(int item) {
    struct NodeBST* temp = new NodeBST;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

NodeBST* insert(struct NodeBST* NodeBST, int key) {

    if (NodeBST == NULL) return newNodeBST(key);

    if (key < NodeBST->key)
        NodeBST->left = insert(NodeBST->left, key);
    else
        NodeBST->right = insert(NodeBST->right, key);

    return NodeBST;
}


NodeBST* minValueNodeBST(struct NodeBST* NodeBST) {
    struct NodeBST* current = NodeBST;


    while (current && current->left != NULL)
        current = current->left;

    return current;
}


NodeBST* deleteNodeBST(struct NodeBST* root, int key) {

    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNodeBST(root->left, key);
    else if (key > root->key)
        root->right = deleteNodeBST(root->right, key);
    else {

        if (root->left == NULL) {
            struct NodeBST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct NodeBST* temp = root->left;
            free(root);
            return temp;
        }

        struct NodeBST* temp = minValueNodeBST(root->right);

        root->key = temp->key;

        root->right = deleteNodeBST(root->right, temp->key);
    }
    return root;
}

int height(NodeBST* p) {
    int l, r, h = 0;
    if (p != NULL) {
        l = height(p->left);
        r = height(p->right);
        h = ((l > r) ? l : r) + 1;
    }
    return h;
}
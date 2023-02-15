#include "avl.h"

int main() {
    NodeAVL* root = NULL;
    root = insertNode(root, 33);
    root = insertNode(root, 13);
    root = insertNode(root, 53);
    root = insertNode(root, 9);
    root = insertNode(root, 21);
    root = insertNode(root, 61);
    root = insertNode(root, 8);
    root = insertNode(root, 11);
    printTree(root, "", true);
    root = deleteNodeAVL(root, 13);
    cout << "After deleting " << endl;
    printTree(root, "", true);

    RedBlackTree bst;
    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    bst.inorder();
    cout << endl;
    bst.postorder();
    cout << endl;
    bst.preorder();
    cout << endl;

    bst.printTree();
    cout << endl
        << "After deleting" << endl;
    bst.deleteNodeRBT(40);
    bst.printTree();

    struct NodeBST* rootb = NULL;
    rootb = insert(rootb, 8);
    rootb = insert(rootb, 3);
    rootb = insert(rootb, 1);
    rootb = insert(rootb, 6);
    rootb = insert(rootb, 7);
    rootb = insert(rootb, 10);
    rootb = insert(rootb, 14);
    rootb = insert(rootb, 4);

    cout << "Inorder traversal: ";
    inorder(rootb);

    cout << "\nAfter deleting 10\n";
    rootb = deleteNodeBST(rootb, 10);
    cout << "Inorder traversal: ";
    inorder(rootb);
}
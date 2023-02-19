#include "avl.h"

int main() {
    NodeAVL* avl = NULL;

    for (int i = 0; i < 1000; i++) {
        avl = insertNode(avl, i);
    }
    /*avl = insertNode(avl, 1);
    avl = insertNode(avl, 2);
    avl = insertNode(avl, 3);
    avl = insertNode(avl, 4);
    avl = insertNode(avl, 5);
    avl = insertNode(avl, 6);
    avl = insertNode(avl, 7);
    avl = insertNode(avl, 8);*/

    printTree(avl, "", true);
    cout << height(avl);
    cout << endl;
    //printTree(avl, "", true);
    //avl = deleteNodeAVL(avl, 13);
    //cout << "After deleting " << endl;
    //printTree(avl, "", true);
    

    RedBlackTree rbt;

    for (int i = 0; i < 1000; i++) {
        rbt.insert(i);
    }

    rbt.printTree();
    cout << endl;
    rbt.height();


    struct NodeBST* bst = NULL;
    bst = insert(bst, 1);
    bst = insert(bst, 2);
    bst = insert(bst, 3);
    bst = insert(bst, 4);
    bst = insert(bst, 5);
    bst = insert(bst, 6);
    bst = insert(bst, 7);
    bst = insert(bst, 8);

    //cout << "Inorder traversal: ";
    //inorder(bst);

    //cout << "\nAfter deleting 10\n";
    //bst = deleteNodeBST(bst, 10);
    //cout << "Inorder traversal: ";
    //inorder(bst);

    //cout << height(bst);
}
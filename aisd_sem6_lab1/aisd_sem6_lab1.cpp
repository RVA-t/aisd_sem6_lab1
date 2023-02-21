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

    //printTree(avl, "", true);
    //cout << height(avl);
    //cout << endl;
    //printTree(avl, "", true);
    //avl = deleteNodeAVL(avl, 13);
    //cout << "After deleting " << endl;
    //printTree(avl, "", true);
    

    RedBlackTree rbt;

    for (int i = 0; i < 10; i++) {
        rbt.insert(i);
    }

    rbt.printTree();
    cout << endl;
    rbt.height();
    cout << endl;


    struct NodeBST* bst = NULL;

    for (int i = 0; i < 1000; i++) {
        bst = insert(bst, i);
    }
    //cout << endl;
    //cout << height(bst);
    //cout << endl;
}
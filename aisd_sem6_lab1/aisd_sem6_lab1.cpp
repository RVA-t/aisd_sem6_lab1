#include "avl.h"

int main() {
    NodeAVL* avl = NULL;

    RedBlackTree rbt;



    struct NodeBST* bst = NULL;
    int x;


    auto savl = chrono::steady_clock::now();

    for (int i = 0; i < 5000; i++) {
        x = rand();
        avl = insertNode(avl, x);
    }
    auto eavl = chrono::steady_clock::now();
    auto durationavl = chrono::duration_cast<std::chrono::nanoseconds>(eavl - savl);


    auto srbt = chrono::steady_clock::now();
    for (int i = 0; i < 5000; i++) {
        x = rand();
        rbt.insert(x);
    }
    auto erbt = chrono::steady_clock::now();
    auto durationrbt = chrono::duration_cast<std::chrono::nanoseconds>(erbt - srbt);




    
    cout << "Duration rbt = " << durationrbt.count() << endl;
    cout << "Duration avl = " << durationavl.count() << endl;

    cout << "avl tree ";
    cout << height(avl);
    cout << endl;
    cout << "rbt tree ";
    rbt.height();
    cout << endl;

    cout << "bst tree ";
    cout << height(bst);
    //cout << endl;
}
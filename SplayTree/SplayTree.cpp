#include "SplayTree.h"
#include <iostream>

int main(){
    SplayTree<int> tree;
   

    tree.insert(15);
     tree.insert(8);
     tree.insert(10);
     tree.insert(3);
     tree.insert(9);
     tree.find(10);
    tree.pintar();
    tree.erase(8);
    tree.pintar();
    tree.insert(7);
    tree.pintar();
    tree.find(15);
    tree.pintar();
    tree.erase(9);
    tree.pintar();
    

    return 0;
}


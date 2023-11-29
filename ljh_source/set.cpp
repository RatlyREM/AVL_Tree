#include <iostream>
#include "AVL.h"

using namespace std;

int main() {
     AVLTree avl_tree_instance;

     avl_tree_instance.insert(10);
     avl_tree_instance.insert(20);

     avl_tree_instance.empty();
     avl_tree_instance.size();
}
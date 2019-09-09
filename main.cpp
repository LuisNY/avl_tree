#include <iostream>
#include <stack>
#include <queue>
#include "avl_tree.h"

int main() {

    auto t = new avl_tree::TREE<int>();

    std::cout << "insert 4" << std::endl;
    t->root = t->insert(t->root, 4);
    std::cout << "insert 8" << std::endl;
    t->root = t->insert(t->root, 8);
    std::cout << "insert 6" << std::endl;
    t->root = t->insert(t->root, 6);
    std::cout << "insert 1" << std::endl;
    t->root = t->insert(t->root, 1);
//    std::cout << "insert 0" << std::endl;
//    t->root = t->insert(t->root, 0);
//    std::cout << "insert 6" << std::endl;
//    t->root = t->insert(t->root, 6);


    std::cout << "IN ORDER TRAVERSAL" << std::endl;
    t->inOrderTraverse(t->root);

    std::cout << "PRE ORDER TRAVERSAL" << std::endl;
    t->PreOrderTraverse(t->root);

    std::cout << "POST ORDER TRAVERSAL" << std::endl;
    t->PostOrderTraverse(t->root);

    std::cout << "height of tree: " << t->getHeight(t->root) << std::endl;

    std::cout << "height difference: " << t->difference(t->root) << std::endl;

    auto temp = t->find(t->root, 9);
    std::cout << "9 " << (temp ? "found" : "not found") << std::endl;

    temp = t->find(t->root, 12);
    std::cout << "12 " << (temp ? "found" : "not found") << std::endl;

    t->deleteNode(t->root, 5);

    std::cout << "IN ORDER TRAVERSAL" << std::endl;
    t->inOrderTraverse(t->root);

    std::cout << "PRE ORDER TRAVERSAL" << std::endl;
    t->PreOrderTraverse(t->root);

    std::cout << "POST ORDER TRAVERSAL" << std::endl;
    t->PostOrderTraverse(t->root);

    return 0;
}
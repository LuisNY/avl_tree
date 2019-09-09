//avl_tree.hpp

#ifndef TREES_AVL_TREE_H
#define TREES_AVL_TREE_H
#include <iostream>
#include <stack>
#include <queue>

namespace  avl_tree {

//forward declaration
template<typename U>
class TREE;

//node of the tree
template<typename T>
class NODE {
    T val;
    NODE *left;
    NODE *right;

    //the TREE class can access the members of NODE
    friend class TREE<T>;

public:
    explicit NODE(T x) : val(x), left(nullptr), right(nullptr) {}
};

template<class T>
class TREE {
public:
    //pointer to the root of the tree
    NODE<T> *root;

    TREE() : root(nullptr) {}

    //methods to traverse the tree
    void inOrderTraverse(NODE<T> *root);
    void PostOrderTraverse(NODE<T> *root);
    void PreOrderTraverse(NODE<T> *root);

    int getHeight(NODE<T> *root);
    int difference(NODE<T> *root);

    //helper methods to keep the tree balanced
    NODE<T> *rotateLeft(NODE<T> *root);
    NODE<T> *rotateRight(NODE<T> *root);
    NODE<T> *balance(NODE<T> *root);

    //insert new node
    NODE<T> *insert(NODE<T> *root, T val);

    //find node
    NODE<T> *find(NODE<T> *root, T val);

    //delete node
    NODE<T> *deleteNode(NODE<T> *root, T val);
};

}

//include .tpp file at the end
#include "avl_tree.tpp"

#endif //TREES_AVL_TREE_H

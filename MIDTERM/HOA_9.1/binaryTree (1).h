#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class BinaryTree {
private:
    T key;
    BinaryTree<T>* leftChild;
    BinaryTree<T>* rightChild;

public:
    // Constructor
    BinaryTree(T rootObjc);

    // Insert child nodes
    void insertLeftChild(T rootObj);
    void insertRightChild(T rootObj);

    // Get child nodes
    BinaryTree<T>* getLeftChild();
    BinaryTree<T>* getRightChild();

    // Get and set root value
    T getrootVal();
    T setrootVal(T obj);

    // Check if node is a leaf
    bool isLeaf();
};


// Constructor
template <typename T>
BinaryTree<T>::BinaryTree(T rootObjc) {
    key = rootObjc;
    leftChild = nullptr;
    rightChild = nullptr;
}


// Insert Left Child
template <typename T>
void BinaryTree<T>::insertLeftChild(T Newnode) {
    if (leftChild == nullptr) {
        leftChild = new BinaryTree<T>(Newnode);
    }
    else {
        BinaryTree<T>* newChild = new BinaryTree<T>(Newnode);

        newChild->leftChild = leftChild;
        leftChild = newChild;
    }
}


// Insert Right Child
template <typename T>
void BinaryTree<T>::insertRightChild(T Newnode) {
    if (rightChild == nullptr) {
        rightChild = new BinaryTree<T>(Newnode);
    }
    else {
        BinaryTree<T>* newChild = new BinaryTree<T>(Newnode);

        newChild->rightChild = rightChild;
        rightChild = newChild;
    }
}


// Get Left Child
template <typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild() {
    return leftChild;
}


// Get Right Child
template <typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild() {
    return rightChild;
}


// Get Root Value
template <typename T>
T BinaryTree<T>::getrootVal() {
    return key;
}


// Set Root Value
template <typename T>
T BinaryTree<T>::setrootVal(T obj) {
    key = obj;
    return key;
}


// Check if Node is a Leaf
template <typename T>
bool BinaryTree<T>::isLeaf() {
    return leftChild == nullptr && rightChild == nullptr;
}

#endif
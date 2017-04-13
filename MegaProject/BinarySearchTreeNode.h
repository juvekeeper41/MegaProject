//
//  BinarySearchTreeNode.h
//  MegaProject
//
//  Created by Osborne, Jacob on 4/11/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef BinarySearchTreeNode_h
#define BinarySearchTreeNode_h

#include "Node.hpp"

template <class Type>
class BinarySearchTreeNode : public Node<Type>
{
private:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreeNode<Type> * root);
    void inOrderTraversal(BinarySearchTreeNode<Type> * inStart);
    void preOrderTraversal(BinarySearchTreeNode<Type> * postStart);
    
public:
    BinarySearchTreeNode();
    
    BinarySearchTreeNode<Type> * getRootPointer();
    BinarySearchTreeNode<Type> * getLeftChild();
    BinarySearchTreeNode<Type> * getRighthild();
    
    void setRootPointer(BinarySearchTreeNode<Type> * root);
    void setLeftChild(BinarySearchTreeNode<Type> * left);
    void setRightChild(BinarySearchTreeNode<Type> * right);
    
    
};

template <classType>
BinarySearchTreeNode :: BinarySearchTreeNode()
{
    this->root = nullptr;
    this->rightChild = nullptr;
    this->leftChild = nullptr;
}

template <class Type>
BinarySearchTreeNode<Type> :: BinarySearchTreeNode(Type data) : Node<Type>(data)
{
    this->root = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTreeNode<Type> :: getLeftChild()
{
    return this->leftChild;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTreeNode<Type> :: getRightChild()
{
    return this->rightChild;
}

template <class Type>
void BinarySearchTreeNode<Type> :: setRootPointer(BinarySearchTreeNode<Type>* right)
{
    this->leftChild = right;
}

template <class Type>
void BinarySearchTreeNode<Type> :: setLeftChild(BinarySearchTreeNode<Type>* left)
{
    this->leftChild = left;
}

template <class Type>
void BinarySearchTreeNode<Type> :: setRightChild(BinarySearchTreeNode<Type>* right)
{
    this->rightChild = right;
}


#endif /* BinarySearchTreeNode_h */

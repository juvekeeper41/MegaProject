//
//  AVLTree.h
//  MegaProject
//
//  Created by Osborne, Jacob on 4/19/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include "BinarySearchTreeNode.h"
#include "BinaryTreeNode.h"

template <class Type>
class AVLTree : public BinarySearchTreee<Type>
{
private:
    
    BinarySearchTreeNode<Type> * leftRotation (BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightRotation (BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * leftRightRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightLeftRotation(BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * balanceSubTree(BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * insertNode(BinarySearchTreeNode<Type> * parent, Type value);
    BinarySearchTreeNode<Type> * removeNode(BinarySearchTreeNode<Type> * parent, Type value);
    
    int heightDifference(BinarySearchTreeNode<Type> * parent);
    
public:
    AVLTree();
    ~AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};
/*
 A negative value means the right is greater than the left
 */
template <class Type>
int AVLTree<Type> :: heightDifference(BinarySearchTreeeNode<Type> * node)
{
    int balance;
    int leftHeight = calculateHeight(node->getLeftChild());
    int rightHeight = calculateHeight(node->getRightChild());
    balance = leftHeight - rightHeight;
    return balance;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<type> * changedNode;
    changedNode = parent->getLeftChild());
    changedNode->setRightChild(parent);
    return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVL<Type> :: rightRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> *  changedNode;
    changedNode = parent->getRightChild();
    
    changedNode->setLeftChild(parent);
    
    return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightLeftRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChild();
    
    parent->setRightChild(leftRotation(changedNode));
    
    return rightRotation(parent);
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRightRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChild();
    
    parent->setRightChild(rightRotation(changedNode));
    
    return leftRotation(parent);
}

template <class Type>
BinarySearchTreeNode<Type> * balanceSubTree(BinarySearchTreeNode<Type> * parent)
{
    int balanceFactor = heightDifference(paret);
    
    if(balanceFactor > 1)
    {
        if(heightDifference(parent->getLeftChild()) > 0)
        {
            parent = leftRotation(parent);
        }
        else
        {
            parent = leftRightRotation(parent);
        }
    }
    else if(balanceFactor < -1)
    {
        if(heightDifference(parent->getRightChild()) > 0)
        {
            parent = rightLeftRotation(parent);
        }
        else
        {
            parent = rightRotation(parent);
        }
    }
    return parent;
}

template <class Type>
AVLTree<Type> :: AVLTree() : BinarySearchTreeType()

{
    
}

template <class Type>


#endif /* AVLTree_h */

//
//  BinaryTreeNode.h
//  MegaProject
//
//  Created by Osborne, Jacob on 4/11/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef BinaryTreeNode_h
#define BinaryTreeNode_h

#include "Tree.hpp"
#include "BinarySearchTreeNode.hpp"

template <class Type>
class BinarySearchTree : public Tree<Type>
{
private:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreeNode<Type> * root);
    void inOrderTraversal(BinarySearchTreenode<Type> * start);
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BinarySearchTreeNode<Type> * postStart);
    
    void removeNode(BinarySearchTreeNode<Type> * & removeMe);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinarySearchTreeNode<Type> * getRoot();
    void setRoot(BinarySearchTreeNode<Type> * root);
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    
    void printToFile();
    
    void demoTraversalSteps(BinarySearchTreeNode<Type> * node);
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
};

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree() : Tree<Type>()
{
    this->root = nullptr;
}

template <class Typee>
BinarySearchTreeNode<Type> * BinarySearchTree<Type> :: getRoot()
{
    return this->root;
}

template <class Type>
void BinarySearchTree<Type> :: setRoot(BinarySearchTreeNode<Type> * root)
{
    this->root = root;
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    
}

template <class Type>
int BinarySearchTree<Tree> :: calculateSize(BinarySearchTreeNode<Type> * start)
{
    return -99;
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraveersal(BinarySearchTreeNode<Type> * inStart)
{
    
}

template <class Type>
void BinarySearchTree :: preOrderTraversal(BinarySearchTreeNode<Type> * preStart)
{
    
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinarySearchTreeNode<Type> * postStart)
{
    
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinarySearchTreeNode<Type> * insertMe = new BinarySearchTreeNode<Type>(itemToinsert);
    BinarySearchTreeNode<Type> * previous = nullptr;
    BinarySearchTreeNode<Type> * current = root;
    if(current == nullptr)
    {
        root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            previous = current;
            if(itemToInsert < current->getNodeData())
            {
                current = current->getLeftChild();
            }
            else if(itemToInsert> current->getNodeData())
            {
                current = current->getRightChild();
            }
            else //Remove cerr after verification of understanding
            {
                cerr << "Item already exists - Exiting" << endl;
                delete insertMe;
                return;
            }
        }
        
        if(previous->getNodeData() > itemToInsert)
        {
            previous->setLeftChild(insertMe);
        }
        else
        {
            previous->setRighChild(insertMe);
        }
        insertMe->setRoot(previous);
    }
}

#endif /* BinaryTreeNode_h */

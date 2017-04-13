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
            previous->setRightChild(insertMe);
        }
        insertMe->setRootPointer(previous);
    }
    
    template <class Type>
    bool BinarySearchTree<Type> :: contains(Type itemToFind)
    {
        BinarySearchTreeNode<Type> * current = root;
        if(current == nullptr)
        {
            return false;
        }
        else
        {
            while(current != nullptr)
            {
                if(itemToFind == current->getNodeData())
                {
                    return true;
                }
                else if(itemToFind < current->getNodeData())
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
            return false;
        }
    }
    
    template <class Typee>
    void BinarySearchTree<Type> :: remove(Type getRidOfMe)
    {
        if(root == nullptr)
        {
            cout << "Empty tree so removal is not possible" endl;
        }
        else
        {
            BinarySearchTreeNode<Type> * current = root;
            BinarySearchTreeNode<Type> * previous = nullptr;
            bool hasBeenFound = false;
            
            while(current != nullptr && !hasBeenFound)
            {
                if(current->getNodeData() == getRidOfMe)
                {
                    hasBeenFound = true;
                }
                else
                {
                    previous = current;
                    if(getRidOfMe < current->getNodeData())
                    {
                        current = current->getLeftChild();
                    }
                    else
                    {
                        current = current->getRightChild();
                    }
                }
            }
            
            if(current == nullptr)
            {
                cerr << "Item not found, removal unsuccessful" << endl;
            }
            else if(hasBeenFound)
            {
                if(current == root)
                {
                    removeNode(root);
                }
                else if(getRidOfMe < previous->getNodeData())
                {
                    removeNode(previous->getLeftChild());
                }
                else
                {
                    removeNode(previous->getRightChild());
                }
            }
        }
        
        template <class Type>
        void BinarySearchTree<Type> :: removeNode(BinarySearchTreeNode<Type> * & removeMe)
        {
            BinarySearchTreeNode<Type> * current;
            BinarySearchTreeNode<Type> * previous;
            BinarySearchTreeNode<Type> * temp;
            
            previous = removeMe->getRoot();
            
            //Leaf - has no child
            if(removeMe->getRightChild() == nullptr && removeMe->getLeftChild() == nullptr)
            {
                temp = removeMe;
                removeMe = nullptr;
                
                if(previous != nullptr && removeMe->getNodeData() < previous->getNodeData())
                {
                    previous->setLeftChild(removeMe);
                }
                
                delete temp;
            }
            //Has only left child
            else if(removeMe->getRightChild() == nullptr)
            {
                temp = removeMe;
                removeMe = removeMe->getLeftChild();
                
                if(previous != nullptr && removeMe->getNodeData() < previous->getNodeData())
                {
                    previous->setLeftChild(removeMe);
                }
                else if(previous != nullptr && removeMe->getNodeData() > previous->getNodeData())
                {
                    previous->setRightChild(removeMe);
                }
                removeMe->setRootPointer(previous);
                
                delete temp;
            }
        }
    }
}

#endif /* BinaryTreeNode_h */

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
protected:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreeNode<Type> * root);
    int calculateHeight(BinarySearchTreeNode<Type> * root);
    bool isBalanced(BinarySearchTreeNode<Type> * root);
    bool isComplete(BinarySearchTreeNode<Type> * root);
    
    void inOrderTraversal(BinarySearchTreeNode<Type> * inStart);
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BinarySearchTreeNode<Type> * postStart);
    
    void removeNode(BinarySearchTreeNode<Type> * removeMe);
    
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
    
    Type findMinimum();
    Type findMaximum();
};

template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTreeNode()
{
    delete this->leftChild;
    delete this->rightChild;
}

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree() : Tree<Type>()
{
    this->root = nullptr;
}

template <class Type>
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
    inOrderTraversal(root);
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinarySearchTreeNode<Type> * current)
{
    BinarySearchTreeNode<Type> * temp = current;
    while(temp->getLeftChild() != nullptr)
    {
        temp = temp->getLeftChild();
    }
    
    return temp;
}

template <class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
    assert(root != nullptr);
    BinarySearchTreeNode<Type> * smallest = getLeftMostChild(root);
    return smallest->getNodeData();
}

template <class Type>
Type BinarySearchTree<Type> :: findMaximum()
{
    assert(root != nullptr);
    BinarySearchTreeNode<Type> * largest = getLeftMostChild(root);
    return largest->getNodeData();
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinarySearchTreeNode<Type> * current)
{
    BinarySearchTreeNode<Type> * temp = current;
    while(temp->getRightChild() != nullptr)
    {
        temp = temp->getRightChild();
    }
    
    return temp;
}

template <class Type>
int BinarySearchTree<Tree> :: calculateSize(BinarySearchTreeNode<Type> * start)
{
    int count = 1;
    if(start == nullptr)
    {
        return 0;
    }
    else
    {
        count += calculateSize(start->getLeftChild());
        count += calclateSize(start->getRightChild());
        return count;
    }
}

template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinarySearchTreeNode<Type> * start)
{
    if(start == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(calculateHeight(start->getLeftChild()), calculateHeight(start-> getRightChild()));
    }
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinarySearchTreeNode<Type> * start)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(start == nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(start->getLeftChild());
    rightHeight = calculateHeight(start->getRightChild());
    
    int heightDifference = abs(leftHeight->rightHeight);
    bool leftBalanced = isBalanced(start->getLeftChild());
    bool rightBalanced = isBalanced(start->getRightChild());
    
    if(heightDifference <= 1 && leftBalanced && rightBalanced)
    {
        return true;
    }
    
    return false;
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinarySearchTreeNode<Type> * inStart)
{
    if(inStart !=nullptr)
    {
        inOrderTraversal(inStart->getLeftChild());
        cout << "Node Contents: " << inStart->getNodeData() << endl;
        inOrderTraversal(inStart->getRightChild());
    }
    
}



/*
 Pre order traversal goes in the order Root, Left, Right
 Notice that the non-recursive case does NOTHING
 */

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinarySearchTreeNode<Type> * preStart)
{
    if(preStart != nullptr)
    {
       
        inOrderTraversal(preStart->getLeftChild());
        inOrderTraversal(preStart->getRightChild());
        cout << "Node Contents: " << postStart->getNodeData() << endl;
    }
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
    
    template <class Type>
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
            //Has only right child
            else if(removeMe->getRightChild() == nullptr)
            {
                temp = removeMe;
                removeMe->getLeftChild();
                
                if(previous != nullptr && removeMe->etNodeData() < previous->getNodeData())
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
            //Has both children
            else
            {
                current = removeMe->getLeftChild();
                previous = nullptr;
                
                while(current->getRightChild() != nullptr)
                {
                    previous = current;
                    current = current->getRightChild();
                }
                
                removeMe->setNodeData(current->getNodeData());
                
                if(previous == nullptr)
                {
                    removeMe->setLeftChild(current->getLeftChild());
                    current->getLeftChild()->setRootPointer(removeMe);
                }
                else
                {
                    previous->setRightChild(current->getLeftChild());
                    current->getLeftChild()->setRootPointer(previous);
                }
            }
            
            if(removeMe == nullptr || removeMe->getRootPointer() == nullptr)
            {
                setRoot(removeMe);
            }
        }
        
        template <class Type>
        int BinarySearchTreeNode<Type> :: getSize()
        {
            return calculateHeight(root);
        }
        
        template <class Type>
        int BinarySearchTreeNode<Type> :: getHeight()
        {
            return calculateHeight(root);
        }
        
        template <class Type>
        bool BinarySearchTreeNode<Type> :: isBalanced()
        {
            return isBalanced(root);
        }
        
        template <class Type>
        bool BinarySearhTreeNode<Type> :: isComplete()
        {
            return isComplete(root);
        }
    }
}

#endif /* BinaryTreeNode_h */

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
    BinarySearchTreeNode<Type> * leftChild;
    BinarySearchTreeNode<Type> * rightChild;
    
public:
    BinarySearchTreeNode();
    
    BinarySearchTreeNode<Type> * getRootPointer();
    BinarySearchTreeNode<Type> * getLeftChild();
    BinarySearchTreeNode<Type> * getRighthild();
    
    void setRootPointer(BinarySearchTreeNode<Type> * root);
    void setLeftChild(BinarySearchTreeNode<Type> * left);
    void setRightChild(BinarySearchTreeNode<Type> * right);
    
    
};


#endif /* BinarySearchTreeNode_h */

//
//  BiDirectionalNode.h
//  MegaProject
//
//  Created by Osborne, Jacob on 2/27/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef BiDirectionalNode_h
#define BiDirectionalNode_h

template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
//    Type data; removed as the data member will be inherited from Node<Type>
    BiDirectionalNode<Type> * nextPointer;
    BiDirectionalNode<Type> * previous;
public:
    BiDirectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type Data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next);
    
//    Type getNodeData();
    BiDirectionalNode<Type> * getNextPointer();
    BiDirectionalNode<Type> * getPreviousPointer();
    
//    void setNodeData(Type data);
    void setNextPointer(BiDirectionalNode<Type> * next);
    void setPreviousPointer(BiDirectionalNode<Type> * previous);
};

template <class Type>
BiDirectionalNode :: BiDirectionalNode() : Node<Type>()
{
    this->nextPointer = nullptr;
    this->previous = nullptr;
}

template <class Type>
BiDirectionalNode :: BiDirectionalNode(Type data) : Node(data)
{
    this->nextPointer = nullptr;
    this->previous = nullptr;
}

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next) : Node(data, next)
{
    this->nextPointer = next;
    this->previous = previous;
}

template <class Type>
void BiDirectionalNode<Type> :: getPreviousPointer(BiDirectionalNode<Type> * previous)
{
    this->previous = previous;
}

#endif /* BiDirectionalNode_h */

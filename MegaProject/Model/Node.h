//
//  Node.h
//  MegaProject
//
//  Created by Osborne, Jacob on 3/13/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef Node_h
#define Node_h

template <class Type>
class Node
{
private:
    Type nodeData;
    Node<Type> * NextPointer;
public:
    Node<Type>();
    Node<Type>(Type data);
    Node<Type>(Type data, Node<Type> * nextPointer);
    
    Type getNodeData();
    Node<Type> * getNextPointer();
    void setNodeData(Type value);
    void setNextPointer(Node<Type> * nextPointer);
};

//Implementation section of the template class.
template <class Type>
Node<Type> :: Node()
{
    NextPointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type data)
{
    this->nodeData = data;
    this->nextPointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type value, Node<Type> * nextNode)
{
    this->nodeData = value;
    this->nextPointer = nextNode;
}

template <class Type>
Type Node<Type> :: getNodeData()
{
    return nodeData;
}

template <class Type>
Node<Type> * Node<Type> :: getNextPointer()
{
    return NextPointer;
}

template <class Type>
void Node<Type> :: setNodeData(Type nodeData)
{
    this->nodeData = nodeData;
}

template <class Type>
void Node<Type> :: setNextPointer(Node<Type> * next)
{
    this->NextPointer = next;
}

#endif /* Node_h */

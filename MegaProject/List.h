//
//  List.h
//  MegaProject
//
//  Created by Osborne, Jacob on 2/21/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef List_h
#define List_h


#include <assert.h>
#include "Node.hpp"

template <class Type>
class List
{
private:
    int size;
    Node<Type> * front;
    Node<Type> * end;
public:
    List<Type>();
    List<Type>(const List<Type> & source);
    ~List<Type>();
    
    int getSize() const;
    Node<Type> * getFront() const;
    Node<Type> * getEnd() const;
    
    void addAtIndex(int index, Type value);
    void add(Type value)
    Type remove(int index)
    Type setAtIndex(int index, Type data)
    Type getFromIndex(int index)
    bool contains(Type data)
    int getSize() const
    Node<Type> * getFront() const
    
    
};

template <class Type>
List<Type> :: List()
{
    this->size = 0;
    this->front = nullpntr;
    this->end = nullpntr;
}

template <class Type>
void List<Type> :: addFront(Type value)
{
     Node<Type> * first = new Node(value);
    if(size == 0)
    {
        Node<Type> * first = new Node(value);
        this->front = first;
        this->end = first;
    }
    else
    {
        Node<Type> * newFirst = new Node<Type>();
        newFirst->setNodeData(value);
        newFirst->setNodePointer(front);
        //or
        //Node<Type> * newFirst = new Node<Type>(value, front);
        front=newFirst;
    }
    
    size++;
}

#endif /* List_h */



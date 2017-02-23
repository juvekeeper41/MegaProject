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
    this->front = nullptr;
    this->end = nullptr;
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

template <class Type>
void List<Type> :: addEnd(Type data)
{
    Node<Type> * added = new Node<Type>(data);
    if(size == 0)
    {
        this->front = added;
        this->end = added;
    }
    else
    {
        end->setnodePointer(added);
        this->end = added;
    }
    size++;
}

template <class Type>
void List<Type> :: addAtIndex(int index, Type value)
{
    assert(index >= 0 && index <= size);
    if(index == 0)
    {
        addFront(value);
    }
    else if(index == size)
    {
        addEnd(value);
    }
    else
    {
        Node<Type> * insertedNode = new Node<Type>(value);
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        previous->setNodePointer(insertedNode);
        insertedNode->SetNodePointer(current);
        
        size++;
    }
    
    template <class Type>
    Type List<Type> :: remove(int index)
    {
        assert(index >= 0 && index < size);
        Type removed;
        
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        Node<Type> * toBeRemoved = nullptr;
        
        
        if(index == 0)
        {
            toBeRemoved = front;
            this->front = front->getNodePointer();
        }
        else if(index == size -1)
        {
            for(int spot = 0; spot < index; spot++)
            {
                previous = current;
                current = current->getNodePointer();
            }
            
            toBeRemoved = current;
            previous->setNodePointer(nullptr);
            this->end = previous;
        }
        else
        {
            for(int spot = 0; spot < index; spot++)
            {
                previous = current;
                current = current->getNodePointer();
        
            }
            toBeRemoved = current;
            current = toBeRemoved->getNodePointer();
            previous-setNodePointer(current);
        }
        removed = toBeRemoved->getNodeData();
        
        delete toBeRemoved;
        
        size--;
        return removed;
    }
    
    
}

#endif /* List_h */



//
//  Stack.h
//  MegaProject
//
//  Created by Osborne, Jacob on 3/1/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "DoublyLinkedList.hpp"

template <class Type>
class Stack : public DoublyLinkedList<Type>
{
private:
public:
    Stack();
    ~Stack();
    void add(Type value);
    Type remove(int index);
    Type pop();
    Type peek();
    void push(Type data);
};

/*
 The add method only adds to the end on a stack. Never at an index.
 */
template <class Type>
void Stack<Type> :: add(Type valueToAdd) : DoublyLinkedList<Type> :: add(valueToAdd)
{
    push(valueToAdd);
}

/*
 Adds the supplied object to the stack to the end.
 Set new object to point to end.

 Adjusts the previous end pointer to reflect the new end of the stack.
 Increases the size by 1.
 */

template <class Type>
void Stack<Type> :: push(Type addedThing)
{
    BiDirectionalNode<Type> * addToStack = new BiDirectionalNode(addedThing);
    
    if(this->size == 0 || this->front == nullptr || this->end == nullptr)
    {
        this->front = addToStack;
    }
   
    else
    {
        this->end->setNextPointer(addToStack);
        addToStack->setPrevousPointer(this->end);
        this->end = addToStack;
    }
    this->end = addToStack;
    this->size++;
}
#endif /* Stack_h */

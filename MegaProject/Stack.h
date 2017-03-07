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
 1. Creates a new node
 2. If the stack is empty set the front to the new node
 3. Else sets the end's next to point to the new node and the new node's previous to end
 4. Move end to the new node
 5. Increases the size by 1.
 */

template <class Type>
void Stack<Type>
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }

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
    
    if(this->getSize() == 0 || this->getFront() == nullptr || this->getEnd() == nullptr)
    {
        this->front(addToStack);
    }
   
    else
    {
        this->getEnd()->setNextPointer(addToStack);
        addToStack->setPrevousPointer(this->getEnd());
        this->end = addToStack;
    }
    this->setEnd(addToStack);
    this->setSize(this->getSize() + 1);
}

/*
 Used to avoid abstract status.
 Asserts that the size is correct and calls the pop method.
 */


template <class Type>
Type Stack<Type> :: remove(int index)
{
    assert(index == this->getSize() - 1 && this->getSize() > 0);
    return pop();
}

/*
 1. Assert size > 0.
 2. Get data from end node.
 3. Move end to end's previous.
 4. Delete old end node.
 5. Decrease size.
 6. Return data from old end.
 */

template <class Type>
Type Stack<Type> :: pop()
{
    assert(this->getSize() > 0);
    Type removed = this->getEnd()->getNodeData();
    
    BiDirectionalNode<Type> * update = this->getEnd();
    update = update->getPreviousPointer();
    
    
    if(update != nullptr)
    {
        update->setNextPointer(nullptr);
    }
    
    delete this->getEnd();
    
    this->setEnd(update);
    
    this->setSize(this->getSize() - 1);
    
    return removed;
}


}
#endif /* Stack_h */

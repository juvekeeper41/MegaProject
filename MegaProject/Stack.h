//
//  Stack.h
//  MegaProject
//
//  Created by Osborne, Jacob on 3/1/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

template <class Type>
class Stack : DoublyLinkedList<Type>
{
private:
public:
    Stack();
    void add(Type value);
};

/*
 The add method only adds to the end on a stack. Never at an index.
 */
template <class Type>
void Stack<Type> :: add(Type valueToAdd) : DoublyLinkedList<Type> :: add(valueToAdd)
{
    
}

#endif /* Stack_h */

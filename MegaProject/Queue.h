//
//  Queue.h
//  MegaProject
//
//  Created by Osborne, Jacob on 3/1/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "DoublyLinkedList.hpp"

template <class Type>
Type Queue<Type> :: remove(int index)
{
    assert(index == 0 && this->getSize() > 0);
    return dequeue();
}

template <class Type>
class Queue : public DoublyLinkedList<Type>
{
    /*
     1. Assert size is valid.
     2. Get data from front node.
     3. If size == 1, set end to nullptr.
     4. Else, move front to front's next.
     5. Delete old front node.
     6. Adjust size down by 1.
     7. Return old value.
     */
    template <class Type>
    Type Queue<Type> :: dequeue()
    {
        assert(this->getSize() > 0);
        
        Type removedValue = this->getFront()->getNodeData();
        BiDirectionalNode<Type> * removeMe = this->getFront();
        
        if(this->getSize() == 1)
        {
            this->setEnd(nullptr);
            this->setFront(nullptr);
        }
        else
        {
            this->setFront(removeMe->getNextPointer());
        }
        this->setFront()->setPreviousPointer(nullptr);
        
        delete removeMe;
        this->setSize(this->getSize() - 1);
        
        return removedValue;
        }
    }
    
    /*
     1. Check that the size is greater than 0.
     2. Return the front object's data.
     */
    template <class Type>
    Type Queue<Type> :: peek()
    {
        assert(this->getSize() > 0);
        
        return this->getFront()->getNodeData();
    }
};

#endif /* Queue_h */

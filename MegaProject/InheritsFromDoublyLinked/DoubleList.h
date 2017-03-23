//
//  DoubleList.h
//  MegaProject
//
//  Created by Osborne, Jacob on 3/3/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef DoubleList_h
#define DoubleList_h

template <class Type>
class DoubleList : public DoublyLinkedList<Type>
{
private:
public:
    DoubleList();
    ~DoubleList();
    void add(Type data);
    Type remove(int index);
    void addAtIndexFast(int index, Type value);
    void addAtIndex(int index, Type value);
    Type getFromIndex(int index);
    Type getFromIndexFast(int index);
};

template <class Type>
DoubleList<Type> :: DoubleList() : DoubleList() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
DoubleList<Type> :: ~DoubleList()
{
    
}

template <class Type>
Type DoubleList<Type> :: getFromindexFast(int index)
{
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type> * reference;
    if(index < this->getSize() / 2)
    {
        reference = this->getFront();
        for(int position = 0; position < index; position++)
        {
            reference = reference->getNextPointer();
        }
    }
    else
    {
        reference = this->getEnd();
        for(int position = this->getSize() - 1; position > index; position--)
        {
            reference = reference->getPreviousPointer();
        }
    }
    
    valueAtIndex = reference->getNodeData();
    return valueAtIndex;
}

//Loop over structure
//Compare Node's data to parameter
//If they match, return index to count of loop
//Else continue
//Return invalid/not in list

template <class Type>
int DoubleList<Type> :: indexOf(Type findMe)
{
    int index = -1;
    
    return index;
}

#endif /* DoubleList_h */

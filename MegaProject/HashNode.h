//
//  HashNode.h
//  MegaProject
//
//  Created by Osborne, Jacob on 5/1/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef HashNode_h
#define HashNode_h

template <class Type>
class HashNode
{
private:
    Type data;
    long key;
public:
    HashNode();
    HashNode(Type data);
    
    Type getData();
    long getKey();
    void setData();
};

template <class Type>
HashNode :: HashNode()
{
    this->key = rand();
}

template <class Type>
HashNode<Type> :: HashNode(Type data)
{
    this->key = rand();
    this->data = data;
}

template <class Type>
void HashNode<Type> :: getData()
{
    return this->data;
}

template <class Type>
void HashNode<Type> :: getKey()
{
    return this->key;
}

#endif /* HashNode_h */

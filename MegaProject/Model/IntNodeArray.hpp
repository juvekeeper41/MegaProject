//
//  IntNodeArray.hpp
//  MegaProject
//
//  Created by Osborne, Jacob on 2/8/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef IntNodeArray_hpp
#define IntNodeArray_hpp
#include "IntNode.cpp"

class IntNodeArray
{
private:
    IntNode * head;
    int size;
public:
    IntNodeArray(int bigness);
    int getSize();
    int getFromIndex(int index, int value);
};

#endif /* IntNodeArray_hpp */

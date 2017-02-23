//
//  StructureController.cpp
//  MegaProject
//
//  Created by Osborne, Jacob on 2/8/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#include "IntNodeArray.hpp"
#include "StructureController.hpp"
#include <iostream>
using namespace std;

StructureController :: StructureController()
{
    
}

void StructureController :: testIntArray()
{
    cout << "Creating an IntNodeArray" << endl;
    IntNodeArray temp = IntNodeArray(3);
    for(int spot =0; spot < 3; spot++)
    {
       cout << temp.getFromIndex(spot) << " is at " << spot << endl;
    }
}

void StructureController :: start()
{
    cout << "Going to test the IntNodeArray" << endl;
    testIntArray();
    cout << "Finished Int Array Node Testing" << endl;
}

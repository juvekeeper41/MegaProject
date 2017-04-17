//
//  StructureController.hpp
//  MegaProject
//
//  Created by Osborne, Jacob on 2/8/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef StructureController_hpp
#define StructureController_hpp

#include "../Model/Node.hpp"
#include "Timer.hpp"
#include "IntNodeArray.hpp"
#include "../Model/List.hpp"
#include "../Model/DoubleList.hpp"
#include "../Model/Stack.hpp"
#include "../Model/Queue.hpp"
#include "../Model/CircularlyLinkedList.hpp"
#include <string>

using namespace std;


class StructureController
{
private:
    Node<int> numberNode;
    Node<sttring> wordNode;
    Array<int> numberArray;
    
    void structureTester();
    void testNodeTypes();
    void testIntArray();
    void testArrayTemplate();
    void testAdvancedFeatures();
    void testListIntro();
    void testListTiming();
    void testDestructor();
    void testDoubleList();
    void testMemeQueue();
    void testNumberStack();
public:
    StructureController();
    void start();
};



#endif /* StructureController_hpp */

//
//  StructureController.cpp
//  MegaProject
//
//  Created by Osborne, Jacob on 2/8/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#include "IntNodeArray.hpp"
#include "StructureController.hpp"
#include "../Model/List.h"
#include <iostream>

using namespace std;

StructureController :: StructureController()
{
    wordNode = Node<string>("derpy");
    numberNode = Node<int>();
    numberArray = Array<int>(0);
}

StructureController :: StructureController()
{
    wordNode = Node<string>("derpy");
    numberNode = Node<int>();
    numberArray = Array<int>(0);
}

void StructureController :: testArrayTemplate()
{
    cout <<"Array Template" << endl;
    Timer arrayTimer;
    arrayTimer.startTimer();
    int test [9];
    arrayTimer.stopTimer();
    arrayTimer.dissplayTimerInformation();
    arrayTimer.resetTimer();
    arrayTimer.startTimer();
    numberArray = Array<int>(9);
    arrayTimer.stopTimer();
    arrayTimer.displayTimerInformation();
    
}

void StructureController :: testNodeTypes()
{
    cout << "Here is a string node: " << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is an uninitialized in node: " << endl;
    cout << numberNode.getNodeData() << endl;
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

for(int spot = 0; spot < 3; spot++)
{
    temp.setAtIndex(spot, spot);
}

void StructureController :: start()
{
    cout << "Going to test the IntNodeArray" << endl;
    testIntArray();
    cout << "Finished Int Array Node Testing" << endl;
    testNodeTypes();
    
    cout << "Testing methods.." << endl;
    testListTiming()
    cout << "Finished testing" << endl;
}


void StructureController :: testListIntro()
{
    List<int> sample;
    sample.addFront(2);
    sample.addFront(3);
    sample.addFront(1);
    cout << sample.getFromIndex(index) << endl;
    
    for(int)
    
}

template <class Type>
Type Queue<Type> :: dequeue()
{
    assert(this->getSize() == 1)
    {
        this->setEnd(nullptr);
        this->setFront(nullptr);
    }
    
    else
    {
        this->setFront(removeMe->getNextPoiner());
        this->getFront()->setPreviousPointer(nullptr);
    }
    
    delete removeMe;
    this->setSize(this->getSize() - 1);
    
    return removedValue;
}

void StructureController :: testIntArray()
{
    
}

void StructureController :: start()
{
    
}

void StructureController :: testDestructor()
{
    
}

void StructureController :: testAdvanedFeatures()
{
    int showDestructor= 0;
    if(showDestructor < 1)
    {
        Array<string> words = Array<string>(5)
        cout << "There should be messsages about destructors next" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "The follwing should match: " << endl;
    cout << words.getFromIndex(0) << " should be the same as " << copiedWords.getFromIndex(0) << endl;
    
    copiedWords.setAtIndex(3, "Contents of the copied Array have been changed");
    
}

void StructureController :: testListIntro()
{
    List<int> sample;
    sample.addFront(2);
    sample.addEnd(3);
    sample.addFront(1);
    cout << "This should go 1, 2, 3" << endl;
    
    for(int index = 0; index < sample.getSize(); index++)
    {
        cout << sample.getFromIndex(index) << endl;
    }
    
    cout << "Size should read 3 and is " << sample.getSize() << endl;
}

void StructureController :: testDoubleLists()
{
    
}

void StructureController :: testListTiming()
{
    DoubleList<int> timingList;
    for(int index = 0; index < 10000; index++)
    {
        timingList.add(rand());
    }
    
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index ++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        fasTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        
        averageSlow += slowTime[index];
        averageFast += averaeFast[index];
    }
    
    averageSlow = averageSlow/1000;
    averageFast = averageFast/1000;
    
    cout << "The average speed for the getFromIndex method was: " << averageSlow << " microseconds" << endl;
    cout << "The average speed for the getFromIndexFast method was: " << averageFast << "microseconds" << endl;
}

void StructureController :: testMemeQueue()
{
    Meme firstMeme("toddler fist! with pinwheel");
    Queue<Meme> memeQueue;
    memeQueue.add(firstMeme);
    Meme secondMeme;
    secondMeme.setDankness(8435);
    memeQueue.enqueue(secondMeme);
    
    Meme temp = memeQueue.dequeue();
    cout << "This dankness should be 8435 and is: " << temp.getDankness() << endl;
}

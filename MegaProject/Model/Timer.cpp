//
//  Timer.cpp
//  SecondProject
//
//  Created by Osborne, Jacob on 1/31/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#include <iostream>
#include "Timer.hpp"

using namespace std;

Timer :: Timer()
{
    executionTime = 0;
}

void Timer :: resetTimer()
{
    executionTime = 0;
}

void Timer :: startTimer()
{
    executionTime = clock();
}

void Timer :: stopTimer()
{
    executionTime = clock() - executionTime;
}

void Timer :: displayTimingInformation()
{
    cout <<  "The execution time is: " << endl;
    cout << "In human time it is" << double (executionTime)/CLOCKS_PER_SEC << " seconds" << endl;
}

long Timer :: getExecutionTimeInMicroseconds()
{
    return executionTime;
}

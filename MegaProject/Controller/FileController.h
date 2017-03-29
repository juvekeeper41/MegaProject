//
//  FileController.h
//  MegaProject
//
//  Created by Osborne, Jacob on 3/29/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef FileController_h
#define FileController_h

#include "../Model/DoubleList.hpp" //Default Structure
#include "../Model/Meme.hpp" //Datatypes
#include "..Model/CrimeData.hpp"
#include <string> //String type
#include <fstream> //File operators
#include <iostream> //console access
#include <sstream> //String as stream

using namespace std; //keyword support

class FileController
{
private:
    DoubleList<Meme> memeList;
public:
    DoubleList<Meme> readMemeDataFromFileAsList(string filename);
    void writeMemeDataStatistics(DoubleList<int> source, string filename);
};


#endif /* FileController_h */

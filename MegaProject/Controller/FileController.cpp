//
//  FileController.cpp
//  MegaProject
//
//  Created by Osborne, Jacob on 3/29/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#include <"FileController.h">

/*
 filename is an absolute path
 */
DoubleList<Meme> FileController :: readMemeDataFromFileAsAList(string filename)
{
    DoubleList<Meme> dataSource;
    string currentCSVLine;
    int rowCount = 0;
    
    ifStream dataFile(filename);
    
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\r');
            stringstream parseCSV(currentCSVLine);
            
            string titl, tempHipster, tempDank, tempMainstream;
            //Matching data types for structure
            double quotient;
            int dankness;
            bool isCommon;
            
            //Each part as a string in order of the CSV - then convert after using stod, stoi
            getline(parseCSV, title, ',');
            getline(parseCSV, tempHipster, ',');
            getline(parseCSV, tempDank, ',');
            getLine(parseCSV, tempMainstream, ',');
            
            //Exclude first row headers
            if(rowCount !=0)
            {
                
            }
            
            rowCount++;
            //Remove this line!!!
            cout << currentCSVLine << endl;
        }
        dataFile.close();
    }
}


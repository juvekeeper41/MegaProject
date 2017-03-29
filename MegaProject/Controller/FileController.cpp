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
                quotient = stod(tempHipster);
                dankness = stoi(tempDank);
                isCommon = stoi(tempMainstream);
                
                Meme temp(title);
                temp.setHipsterQuotient(quotient);
                temp.setDankness(dankness);
                temp.setMainstream(isCommon);
                
                dataSource.add(temp);
            }
            
            rowCount++;
            //Remove this line!!!
            cout << currentCSVLine << endl;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    
    return dataSource;
}

void FileController :: writeDataStatistics(DoubleList<Meme> dataSource, string filename)
{
    ofstream saveFile(filename);
    
    if(saveFile.is_open())
    {
        saveFile << "These are the contents of the list" << endl;
        for(int index = 0; index < dataSource.getSize(); index++)
        {
            saveFile << "Meme Title: " << dataSource.getFromIndex(index) << endl;
            
        }
        else
        {
            cerr << "File Unavailable" << endl;
        }
        saveFile.close();
    }
}


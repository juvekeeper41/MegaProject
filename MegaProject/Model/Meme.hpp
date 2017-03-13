//
//  Meme.hpp
//  MegaProject
//
//  Created by Osborne, Jacob on 3/13/17.
//  Copyright © 2017 Osborne, Jacob. All rights reserved.
//

#ifndef Meme_hpp
#define Meme_hpp
#include <string>

using namespace std;

class Meme
{
private:
    string title;
    int dankness;
    double hipsterQuotient;
    bool mainstream;
public:
    Meme();
    Meme(string title);
    int getDankness();
    double getHipsterQuotient();
    bool isMainstream();
    string getTitle();
    void setTitle(string title);
    void setDankness(int dank);
    void setHipsterQuotient(double  hipsterQuotient);
    void setMainstream(bool mainstream);
    
};

#include <stdio.h>

#endif /* Meme_hpp */

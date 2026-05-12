//
//  BitRepresentation.hpp
//  CS204HW6BIT
//
//  Created by Eralp  Kızıloğlu on 26.12.2022.
//

#ifndef BitRepresentation_hpp
#define BitRepresentation_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class BitRepresentation{
    
public:
    BitRepresentation(T number); //constructor
    BitRepresentation(vector<bool> a);//constructor
    string getBinary(); //gives us binary representation in string
    string getHexadecimal();//gives us hexadecimal of the integer
    void setBit(unsigned int location); //sets 1 to the location given as parameter
    void unsetBit(unsigned int location); //unsets by putting 0 to location given as parameter
    bool isBitSet(unsigned int location); //checks the position if it is 1 or 0 by returning true false respectively
    T getNumber(); //returns the data member
    
    
    
    
    
private:
    T data; //private data member

    
    
};








#include "BitRepresentation.cpp"
#endif /* BitRepresentation_hpp */

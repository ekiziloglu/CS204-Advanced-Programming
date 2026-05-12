//
//  BitRepresentation.cpp
//  CS204HW6BIT
//
//  Created by Eralp  Kızıloğlu on 26.12.2022.
//

#include "BitRepresentation.hpp"

#include <iostream>
#include <vector>
#include <string>



using namespace std;


template <typename T>
BitRepresentation<T>::BitRepresentation(T number):data(number)
{}//constructor for BitRepresantation data stores value


template <typename T>
BitRepresentation<T>::BitRepresentation(vector <bool> a){
    
    int vectorSize,i;
    vectorSize = a.size();//vector size
    
    int DataBits;
    DataBits = sizeof(data) * 8;//data in bits
    
    string emptystr = ""; //empty string
    
    if(vectorSize < DataBits){//checks if vectorsize is smaller than data bits
        
        for(i = 0 ; i < vectorSize; i++){
            
            if(a[i] == true){
                emptystr += '1';
            }
            else{
                emptystr += '0';
            }
            
        }
        int difference = DataBits - vectorSize;
        for(i = 0 ; i < difference ; i++){
            emptystr = "0" + emptystr;
        }
        
    }
    
    else if(vectorSize > DataBits){//case when vector size is bigger than databits
        int difference = vectorSize - DataBits;
        
        for(i = difference; i < vectorSize ; i++){
            if(a[i] == true){
                emptystr += '1';
            }
            else{
                emptystr += '0';
            }
        }
        
    }
    
    else{
        for(i = 0 ; i < vectorSize; i++){//case when vector size and data in bits are equal
            if(a[i] == true){
                emptystr += '1';
            }
            else{
                emptystr += '0';
            }
    }
    
    
    
    
}
    //cout<<emptystr<<endl;
    

}
   


template <typename T>
string BitRepresentation<T>::getBinary(){
    
    string temp = ""; //creating empty string initially
    
    int sizeofType; //stores byte amount
    sizeofType = sizeof(data);
    //cout<<sizeofType<<endl;
    
    char * list  = new char[8 * sizeofType ]; //using a pointer array of chars
    //list[sizeofType*8] = '\0';
    T copy_data = data;
    for(int i = 0; i < (sizeofType*8); i++)
    {
        if((copy_data & 1) == 1)
        {
            list[(sizeofType*8-1)-i] = '1';
        }
        else
        {
            list[(sizeofType*8-1)-i] = '0';
        }

        copy_data = copy_data >> 1;
    }
    
    for(int i = 0 ; i < (sizeofType*8) ; i++ ){
        temp += list[i];
    }
    
    
    return temp;
    
}

template <typename T>
string BitRepresentation<T>::getHexadecimal(){
    string hexadecimal = "";
    
    int characternum;
    characternum = sizeof(data) * 2;
    
    string arr[] = {"A","B","C","D","E","F"};
    
    
    
    
    
    return hexadecimal;
    
    
}

template <typename T>
void BitRepresentation<T>::setBit(unsigned int location){
    //getBinary();
    //comparison
    if(sizeof(data)*8 <= location){//case when location given is bigger than bits, then we do nothing
        return;
    }
    data = data | (1 << location);
    
}


template <typename T>
void BitRepresentation<T>::unsetBit(unsigned int location){
    if(sizeof(data)*8 <= location){
        return;//function returns nothing and finishes
    }
    data = data^(1 << location);
    
}

template <typename T>
bool BitRepresentation<T>::isBitSet(unsigned int location){
    
    if(location > (sizeof(data)*8)){//case when location given is bigger than bits, then we do nothing
        return false;
    }
     
    T check;
    check = 1 << (location - 1);
    
    
    return (check & data);
     
    
}


template <typename T>
T BitRepresentation<T>::getNumber(){
    return data;
}


    





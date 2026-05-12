//
//  templateclass.hpp
//  TEMPLATEDCLASSES
//
//  Created by Eralp  Kızıloğlu on 5.12.2022.
//

#ifndef templateclass_hpp
#define templateclass_hpp

#include <iostream>
#include <stdio.h>
#include <string>

template <class OpType>
class Add
{
public:
    Add (OpType op1, OpType op2);
    OpType operand (int i);
    OpType result ();
private:
    OpType myOp1, myOp2;
};





#include "templateclass.cpp" //don't forget and remove reference of cpp file
#endif /* templateclass_hpp */

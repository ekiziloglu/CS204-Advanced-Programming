//
//  templateclass.cpp
//  TEMPLATEDCLASSES
//
//  Created by Eralp  Kızıloğlu on 5.12.2022.
//

#include "templateclass.hpp"

#include <string>
#include <iostream>
using namespace std;


template <class OpType>
Add<OpType>::Add (OpType a, OpType b)
    :myOp1(a), myOp2(b)
{}

template <class OpType>
OpType Add<OpType>::operand (int i)
{   if (i==1)    return myOp1;
    else return myOp2;
}

template <class OpType>
OpType Add<OpType>::result ()
{   return myOp1 + myOp2;
}

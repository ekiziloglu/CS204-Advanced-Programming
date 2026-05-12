//
//  main.cpp
//  NUMBERREPRESENTATION
//
//  Created by Eralp  Kızıloğlu on 6.12.2022.
//

#include <iostream>

using namespace std;

int main(){
    
    char S = 99; //valid
    cout<<S<<endl;
    
    char ch = 135;
    cout<<ch<<endl;
    
    cout<<int(ch)<<endl;//-121 in bits representation
    //Outputissignedinteger(2'scomplement)representationof135(in32bits). 13510 = 11111111 11111111 11111111 100001112 which is -121 in 2's complement representation. Thus you see -121 as the output
    
    unsigned char x;
    x = -25;
    cout<<x<<endl;//-25isoutofrangebutcanberepresentedin2'scomplementas11100111in binary and the unsigned interpretation of this bit string is 231 displays the character for which the ASCII code is 231.
    
    unsigned short num;
    num = -25;
    cout << num<<endl;
    //-25 is negative so it is represented using 2's complement. The resulting bit string is then interpreted as an unsigned number since it is assigned to unsigned number (implicit type casting).
    
    /*
    unsigned int j;
    for (j = 5; j >= 0; j--){ //infinite loop,when it is decremented after 0 becomes -1 and interpreted as unsigned int
        cout << j << endl;
    }
     */
        
    //Moral of the story: use unsigned only if you make sure that the value of the variable will never go below 0. Otherwise use signed integers.
    
    
    //Do not mix signed and unsigned numbers in an expression. Some strange things may happen. Consider the following code:

    unsigned int a = 5;
        int b = -10;
        if (a+b < 0)
            cout << "hede" << endl;
        else
            cout << "hodo" << endl;
    
    //In C++, there is a rule saying that built-in operands of an operator must be of the same type. If they are different, one of them is implicitly typecasted to the other before evaluating the expression.

    
    short n = 45000; //complier warns//However, if you assign an expression that goes beyond the capacity, then compiler cannot see this and cannot warn you. This is a big problem and technically called as "overflow"
    
    return 0;
}

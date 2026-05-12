//
//  main.cpp
//  CS204HW6BIT
//
//  Created by Eralp  Kızıloğlu on 26.12.2022.
//

#include <iostream>
#include "BitRepresentation.hpp"
#include <string>

using namespace std;



int main(){
    
    
    /*
    int a = 10;
    BitRepresentation<int> x(a);
    
    short int f = 5;
    BitRepresentation<short> y(f);
   */

     
    
    
    /*
    vector<bool> v1 = {true, false, true, false}; // == 0b1010 BitRepresentation<char> s1(v1); // s1.data = 0b00001010
    BitRepresentation<char> s1(v1); // s1.data = 0b00001010

    
    vector<bool> v2 = {true, true, true, true, false, false, false, false};
    BitRepresentation<char> s2(v2); // s2.data = 0b11110000
    
    
    vector<bool> v3 = {true, false, false, true, true, true, true, true, true, false, false, false, false};
    BitRepresentation<char> s3(v3);
     */
    
    /*
    
    BitRepresentation<short> x(0);
    cout << x.getHexadecimal() << endl;
    BitRepresentation<short> y(12351);
    cout << y.getHexadecimal() << endl;
    */
    
    /*
    BitRepresentation<int> x(0);
    cout << x.getBinary() << endl;
    BitRepresentation<int> y(11);
    cout << y.getBinary() << endl;
    
    BitRepresentation<char> z(8); //why does it only print zero with chars?
    cout<<z.getBinary()<<endl;
     */
    
    /*
    BitRepresentation<char> x(5);
    x.setBit(0);
    cout << x.getBinary() << endl;
    x.setBit(1);
    cout << x.getBinary() << endl;
    x.setBit(6);
    cout << x.getBinary() << endl;
    //x.setBit(8); // function will do nothing in this case cout << x.getBinary() << endl;
    */
    
    /*
    BitRepresentation<char> x(255);
    cout << x.getBinary() << endl;
    x.unsetBit(0);
    cout << x.getBinary() << endl;
    x.unsetBit(1);
    cout << x.getBinary() << endl;
    x.unsetBit(6);
    cout << x.getBinary() << endl;
    x.unsetBit(8); // function will do nothing in this case cout << x.getBinary() << endl;
    cout<<x.getBinary() <<endl;
    */
    
    
    /*
    BitRepresentation<char> x(255);
    cout << x.getBinary() << endl;
    
    x.unsetBit(0);
    cout << x.getBinary() << endl;
    
    x.unsetBit(1);
    cout << x.getBinary() << endl;
    
    
    x.unsetBit(6);
    cout << x.getBinary() << endl;
    
    
    cout << x.isBitSet(0) << endl;
    cout << x.isBitSet(2) << endl;
    cout << x.isBitSet(6) << endl;
    cout << x.isBitSet(11) << endl;
     */
    
    
    
    /*
    BitRepresentation<short> s(0);
    s.setBit(0);
    s.setBit(1);
    s.setBit(3);
    short number = s.getNumber();
    cout << number << endl;
    */
    
    

    
    return 0;
}

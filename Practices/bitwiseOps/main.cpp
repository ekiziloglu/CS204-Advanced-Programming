//
//  main.cpp
//  BITWISEOPS
//
//  Created by Eralp  Kızıloğlu on 6.12.2022.
//

#include <iostream>

using namespace std;

int main(){
    /*
    char x = 0xA5;
    
    if ( x & 0x08 ){
        cout<<"Yes"<<endl;
        
    }
    
    x = x | 0x02;
    
    cout<<x<<endl;
    
    cout<<endl;
     */
    
    char x,y,z;
    
    x = 0x33;
    x = (x << 3) | 0x0F;
    y = (x >> 1) & 0x0F;
    z = x && y;
    
    //cout<<x<<endl;
    //cout<<y<<endl;
    cout<<hex<<z<<" "<<dec<<z<<endl;
    
    return 0;
}

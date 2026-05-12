//
//  main.cpp
//  TEMPLATEDCLASSES
//
//  Created by Eralp  Kızıloğlu on 5.12.2022.
//

#include <iostream>
#include <string>

#include "templateclass.hpp"

using namespace std;

int main()
{
    Add<int> a(5, 12);
    cout << a.operand(1) << " + " << a.operand(2)
        << " = " << a.result() << endl;
    
    Add<string> b("cs", "204");
    cout << b.operand(1) << " + " << b.operand(2)
        << " = " << b.result() << endl;

    Add<char> c('2', '3');
    cout << c.operand(1) << " + " << c.operand(2)
        << " = " << c.result() << endl;
    
    cout<<"hello"<<endl;
    
    return 0;

}

//
//  main.cpp
//  cs204Stacks
//
//  Created by Eralp  Kızıloğlu on 19.11.2022.
//

#include <iostream>
#include "IntStack.h"

using namespace std;

int main(){
    IntStack  stack(5);
    int num;
    cout << "Created an empty stack with capacity 5, trying to pop. \n";
    stack.pop(num);

    int values[] = {2, 7, 10, 5, 3, 8, 11};

    cout << "\nPushing...\n";
    for (int k = 0; k < 7; k++)
    {
        cout << values[k] << "  ";
        stack.push(values[k]);
        cout << endl;
    }
    
    
    cout << "\nPopping...\n";
    while (!stack.isEmpty())
    {
        stack.pop(num);
        cout << num << endl;
    }
    cout << endl;
    
  

    
    
    
    return 0;
}

#include <iostream>
#include "LinkedList.h"

using namespace std;

// foo(lhs, rhs); // free
// lhs.foo(rhs); // member 

#define SQUARE(x) x*x


LinkedList operator*(const LinkedList & lhs, const LinkedList & rhs){
    LinkedList result(lhs);
    for(int i=0; i<rhs.getSize(); i++){
        result[i] *= rhs[i];
    }
    return result;
}

// cout << a << b << c << endl;
ostream& operator<<(ostream& out, const LinkedList & rhs){
    for(int i=0; i<rhs.getSize(); i++){
        out << rhs[i] << " ";
    }
    out << endl;
    return out;
}

// a[5] = 10;
int main(){
    int * arr = new int[5];

    for(int i=0; i<5; i++){
        arr[i] = i*2;
    }

    LinkedList l1(arr, 5);

    for(int i=0; i<5; i++){
        arr[i] = i*3;
    }
    LinkedList l2(arr, 5);

    cout << l1 << endl;
    cout << l2 << endl;
    cout << l1+l2 << endl;
    cout << l1*l2 << endl;

    delete [] arr;

    return 0;
}

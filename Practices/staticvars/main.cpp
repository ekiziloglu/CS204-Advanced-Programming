//
//  main.cpp
//  cs204staticvars
//
//  Created by Eralp  Kızıloğlu on 18.11.2022.
//

#include <iostream>
using namespace std;

void showstat( int curr ) {
  static int nStatic = 0 ;    // Value of nStatic is retain between each function call
  nStatic += curr;
  cout << "nStatic is " << nStatic << endl;
}

int main() {
  for ( int i = 0; i < 5; i++ ) {
    showstat( i );
  }
}
//program does not reset static int nstatic to zero everytime it enters the function showstat

//
//  main.cpp
//  FUNCTIONOVERLOAD
//
//  Created by Eralp  Kızıloğlu on 5.12.2022.
//

#include <iostream>
using namespace std;

double max( double d1, double d2 ) {
  cout << "double max " << endl;
  if ( d1 > d2 )
    return d1;
  else
    return d2;
    }

int max( int i1, int i2 ) {
  cout << "int max " << endl;
  if ( i1 > i2 )
    return i1;
  else
    return i2;
}
 
void fun(int i) { cout << i << " - " << endl;}
void fun(float f) { cout << f << " + " << endl;}

void fun2(int i){cout << i << " - " << endl;}
void fun2(int &i){cout << i << " + " << endl;}

int fun3(int i) {cout << "int return" << endl; return 1;}
//double fun3(int i) {cout << "double return" << endl; return 1.0;}
 
int main() {
    
    
    int i;
    double d ;
    i = max( 12, 8 );//gives int max on output
    d = max( 17.4, 32.9 ); //gives double max on output
    
    
  //cout << i << " " << d << " " << max(12, 33.3); //ambiguous(open to more than one interpretation)

  fun(10); //10 -
  fun(10.245f); //ambiguous //10.245 +

  fun2(10);
  //fun2(i); // ambiguous

    //cout<<10.245f<<endl; just gives 10.245f on output
  return 0;
}

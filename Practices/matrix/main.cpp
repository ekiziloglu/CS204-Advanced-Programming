//
//  main.cpp
//  cs204pracweek3
//
//  Created by Eralp  Kızıloğlu on 16.11.2022.
//

#include <iostream>
#include <string>
#include "matrixclass.h"




using namespace std;



void createBlock(){
    cout<<endl;
    cout<<endl;
}


void print_table(int** values,  int num_rows, int num_cols)
{
  int i, j;
  
  for (i = 0; i < num_rows; i++) {
    for (j= 0 ; j< num_cols ; j++)
      cout << values[i][j] << " ";
    cout << endl;
  }
}


int main(){
    
    Matrix1D m(5,10); //a 5x10 matrix 5rows,10columns
    
    m.SetIndex(0, 5, 33);
    
    cout<<m.GetIndex(0, 5)<<endl;
    
    //creating 2D array implicitly
    
    createBlock();
    
    int **    nums;
    int rows, columns, i,j;
    
    cout<< "Enter the number of rows: ";
    cin >> rows;
    cout<< "Enter the number of columns: ";
    cin >> columns;
    
    /************ Allocate Memory for the 2d Array ************/
    // nums is an array of int pointers
    nums = new int*  [rows];
    
    // each nums [i] is an array of ints.
    for (i = 0; i<rows; i++)
      nums[i] = new int  [columns];
    
    
    /******************* Read In the Entries ******************/
    cout << "Enter the elements" << endl;
    
    for (i = 0; i < rows; i++)
      {
        for (j= 0 ; j< columns ; j++)
      {
        cout<< '[' << i << ',' << j << "]: ";
        cin >> nums[i][j];
        cout<< endl;
      }
      }
    
    nums[0][0] = 45; //this is allowed unless it is in the range
    
    // Print the whole matrix table
    print_table(nums, rows, columns);
    
    // Returning memory to free heap for reuse
    for (i = 0; i< rows; i++)
      delete [] nums[i];
    delete [] nums;
    
    //or we can just use classes to create 2d matrix explicitly
    
    int my2d[3][5]; //this can be used for 2d array
    
    
    
    
    
    
    
    return 0;
}

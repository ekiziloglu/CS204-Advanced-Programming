#include "matrixclass.h"

// This is the first way we saw in the lectures
// Uses a single array and mimics the 2D indexing by member functions
Matrix1D::Matrix1D(int r, int c)
{
  rows = r;
  cols = c;
  int size = rows * cols;
  data = new int [size];	 //this is a one long array of ints – 1D			
}

int Matrix1D::GetIndex(int i, int j)
{
  return data[i*cols+j];
}

void Matrix1D::SetIndex(int i, int j, int value)
{
  data[i*cols+j] = value;
}

/*********************************************************/

//This class does the same, but uses a pointer to pointers to
//generate the matrix. Indexing comes with it. 
Matrix2D::Matrix2D(int r, int c)
{
  rows=r;
  cols=c;
  data = new int* [r]; 
  
  for (int i = 0; i<rows; i++) 
    data[i] = new int[cols];
  
}

int Matrix2D::GetIndex(int i, int j)
{
  return data[i][j];
}

void Matrix2D::SetIndex(int i, int j, int value)
{
  data[i][j] = value;
}

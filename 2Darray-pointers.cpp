#include<iostream>
#include<chrono>
#include<cmath>
using namespace std;

int mult(int *, int *);//function for performing the same multiplication as first program but instead using pointers to get the numbers from the array

int main(){
  int rows = 21;
  int cols = 21;
  int myArray[21][21];//creating a 21x21 2D array

  auto start_time = chrono::steady_clock::now();
  for(int i = 1; i < rows; i++){//creating a multiplication table up to 20 using pointers
    for(int j = 1; j < cols; j++){
      myArray[i][j] = mult(&i, &j);
    }
  }
  auto end_time = chrono::steady_clock::now();
  auto time = end_time - start_time;
  cout<<"The time taken to create a multiplication table = "<<chrono::duration_cast<chrono::nanoseconds>(time).count()<<"ns"<<endl;

  //As I did for the first program, I also verified that this multiplication table was the same and it was.
  for(int i = 1; i < rows; i++){//printing out the table
    for(int j = 1; j < cols; j++){
      cout<<myArray[i][j]<<'\t';
    }
    cout<<endl;
  }

  return 0;
}

int mult(int *x, int *y){//pointer arithmetic
  int res;
  res = (*x * *y);
  return res;
}

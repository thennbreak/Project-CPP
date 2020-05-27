#include<iostream>
#include<chrono>
#include<cmath>
using namespace std;

int main(){
  int rows = 21;
  int cols = 21;
  int myArray[21][21];//creating a 21x21 2D array

  auto start_time = chrono::steady_clock::now();
  for(int i = 1; i < rows; i++){//creating a multiplication table up to 20 using subscipts only
    for(int j = 1; j < cols; j++){
      myArray[i][j] = i * j;
    }
  }
  auto end_time = chrono::steady_clock::now();
  auto time = end_time - start_time;
  cout<<"The time taken to create a multiplication table = "<<chrono::duration_cast<chrono::nanoseconds>(time).count()<<"ns"<<endl;

//Checked to make sure the multiplication table was correct by printing it out, it was.
  for(int i = 1; i < rows; i++){
    for(int j = 1; j < cols; j++){
      cout<<myArray[i][j]<<'\t';
    }
    cout<<endl;
  }
  return 0;
}

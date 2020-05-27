//C++ Code to test the effieciency of different data structures.

#include<iostream>
#include<chrono>//using chrono to clock the times of execution
using namespace std;

void staticArray();
void stack(int x);
void heap(int y);

int main(){
  int a = 100000;//number of declartions
  int b = 250000;//number of elements for stack and heap

  //Static Array
  auto start_time = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < a; i++){//declaring the static array 100,000 times
    staticArray();
  }
  auto end_time = std::chrono::high_resolution_clock::now();
  auto time = end_time - start_time;
  cout<<"The amount of time via using a static array = "<<time/std::chrono::milliseconds(1)<<"ms"<<endl;

  //Stack from array
  auto start_time2 = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < a; i++){//declaring the stack 100,000 times
    stack(b);
  }
  auto end_time2 = std::chrono::high_resolution_clock::now();
  auto time2 = end_time2 - start_time2;
  cout<<"The amount of time via using a stack = "<<time2/std::chrono::milliseconds(1)<<"ms"<<endl;

  //Heap from array
  auto start_time3 = std::chrono::high_resolution_clock::now();
  try{//error catching for not enough memory to declare the heap 100,000 times
    for(int i = 0; i < a; i++){//declaring the heap 100,000 times
      heap(b);
    }
  }
  catch (const std::bad_alloc& ex){
    cout<<"Not enough memory."<<endl;
    return -1;
  }
  auto end_time3 = std::chrono::high_resolution_clock::now();
  auto time3 = end_time3 - start_time3;
  cout<<"The amount of time via using a heap = "<<time3/std::chrono::milliseconds(1)<<"ms"<<endl;

  return 0;
}

void staticArray(){
  static int array[250000];//creating a static array of 250,000 elements
}
void stack(int x){
  int myStack[x];//ceating a stack from an array which also has 250,000 elements
}
void heap(int y){
  int *array = new int[y];//creating a heap from an array which also has 250,000 elements
  delete [] array;
}

#include<iostream>
using namespace std;
int main(){
  try{throw runtime_error("Runtime Error Thrown here");}
  catch(...){
    cout<<"Exception Caught here";//can catch all types of errors
  }
  return 0;
}

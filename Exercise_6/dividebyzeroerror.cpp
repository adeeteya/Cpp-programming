#include<iostream>
using namespace std;
int intDivEx(int numerator,int denominator){
  if(denominator==0)
    throw overflow_error("Division By Zero Error");
  return numerator/denominator;
}
int main(){
  cout<<"42/7= "<<intDivEx(42,7)<<endl;
  try{cout<<"35/0= "<<intDivEx(35,0);}
  catch(overflow_error e){
    cout<<e.what();
  }
  return 0;
}

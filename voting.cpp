#include<iostream>
using namespace std;
int main(){
  cout<<"Enter your age: ";
  int age;
  cin>>age;
  if(age>=18)
    cout<<"You are eligible to vote";
  else
    cout<<"You are not eligible to vote";
  return 0;
}

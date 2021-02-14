#include<iostream>
using namespace std;
void display(int x){
  cout<<"Value of x inside function: "<<x<<endl;
  x=500;
  cout<<"Value of x inside function(after changing): "<<x<<endl;
}
int main(){
  int x=100;
  cout<<"Original value of x: "<<x<<endl;
  display(x);
  cout<<"Value of x outside the function: "<<x;
  return 0;
}

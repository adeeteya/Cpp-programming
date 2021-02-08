#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int a,b,c;float d;
  cout<<"Enter the co-efficient of x^2: ";
  cin>>a;
  cout<<"Enter the co-efficient of x: ";
  cin>>b;
  cout<<"Enter the value of the constant c: ";
  cin>>c;
  d=b*b-(4*a*c);
  if(d>0){
    float x1,x2;
    x1=((-b)+sqrt(d))/(2*a);
    x2=((-b)-sqrt(d))/(2*a);
    cout<<"The roots of the equation are:\nx1= "<<x1<<"\nx2= "<<x2;
  }
  else if(d==0){
    float x=-b/(2*a);
  cout<<"The root of the equation is: x= "<<x;
  }
  else
    cout<<"The roots are imaginary";
}

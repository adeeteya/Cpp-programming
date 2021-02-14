#include<iostream>
using namespace std;
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int main(){
  int x=100,y=700;
  cout<<"Value before swapping\n";
  cout<<"x= "<<x<<" y= "<<y<<endl;
  swap(&x,&y);
  cout<<"Value after swapping\n";
  cout<<"x= "<<x<<" y= "<<y<<endl;
  return 0;
}

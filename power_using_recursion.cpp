#include<iostream>
using namespace std;
int power(int n,int pow){
  if(pow==0)
    return 1;
  else if(pow==1)
    return n;
  else
    return n*power(n,pow-1);
}
int main(){
  int n,pow;
  cout<<"Enter a number: ";
  cin>>n;
  cout<<"Enter it's power: ";
  cin>>pow;
  cout<<n<<" To The power of "<<pow<<" is "<<power(n,pow);
  return 0;
}

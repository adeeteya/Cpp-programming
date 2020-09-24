#include<iostream>
using namespace std;
int isPrime(int n){
  int factors=0,i;
  for(i=1;i<=n;i++)
    if(n%i==0)
      factors++;
  if(factors==2)
    return 1;
  else
    return 0;
}
int main(){
  int n,i,j;
  cout<<"Enter a positive integer: ";
  cin>>n;
  if(n<0){
    cout<<"Inavlid input";
    return -1;
  }
  for(i=2;i<=n/2;i++){
    j=n-i;
    if(isPrime(j) && isPrime(i))
      cout<<n<<"="<<i<<"+"<<j<<endl;
  }
}

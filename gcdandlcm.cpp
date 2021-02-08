#include<iostream>
using namespace std;
class numbers{
public:
  int a,b;
  int lcm(){
    int max=(a>b)?a:b;
    for(int i=max;i<=a*b;i++)
      if(i%a==0 && i%b==0)
        return i;
  }
  int gcd(){
    int min=(a<b)?a:b;
    for(int i=min;i>0;i--)
      if(a%i==0 && b%i==0)
        return i;
  }
};
int main(){
  numbers n;
  cout<<"Enter the First number: ";
  cin>>n.a;
  cout<<"Enter the Second Number: ";
  cin>>n.b;
  cout<<"The Lcm of "<<n.a<<" and "<<n.b<<" is "<<n.lcm();
  cout<<"\nThe Gcd of "<<n.a<<" and "<<n.b<<" is "<<n.gcd();
  return 0;
}

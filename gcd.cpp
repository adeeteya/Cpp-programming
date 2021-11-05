#include<iostream>
using namespace std;
int gcd(int m,int n){
    if(n==0)
        return m;
    return gcd(n,m%n);
}
int main(){
    int n,m;
    cout<<"Enter the first number: ";cin>>n;
    cout<<"Enter the second number: ";cin>>m;
    int result=(n>m)?gcd(n,m):gcd(m,n);
    cout<<"The gcd of "<<n<<" and "<<m<<" is "<<result;
    return 0;
}

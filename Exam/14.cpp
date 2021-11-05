#include<iostream>
using namespace std;
template<typename T>
void maxmin(T a[],int n){
  T max=a[0],min=a[0];
  for(int i=0;i<n;i++){
    if(max<a[i])max=a[i];
    if(min>a[i])min=a[i];
  }
  cout<<"Minimum Value: "<<min<<"\nMaximum Value: "<<max<<endl;
}
template<typename T>
void swap(T *a,T *b){
  T temp=*a;
  *a=*b;
  *b=temp;
}
template<typename T>
void sort(T a[],int n){
  for(int i=0;i<n-1;i++)
    for(int j=0;j<n-i-1;j++)
      if(a[j+1]<a[j])
        swap(a[j],a[j+1]);
}
int main(){
  int n,i;
  cout<<"Enter the number of elements: ";cin>>n;
  int intarr[n];
  cout<<"Enter the elements of the Integer array: ";
  for(i=0;i<n;i++)
    cin>>intarr[i];
  maxmin<int>(intarr,n);
  sort<int>(intarr,n);
  cout<<"The Sorted Integer Array is\n";
  for(i=0;i<n;i++)
    cout<<intarr[i]<<" ";
  cout<<"\nEnter the number of elements of double array: ";cin>>n;
  double doublearr[n];
  cout<<"Enter the elements of the double array: ";
  for(i=0;i<n;i++)
    cin>>doublearr[i];
  maxmin<double>(doublearr,n);
  sort<double>(doublearr,n);
  cout<<"The Sorted Double Array is\n";
  for(i=0;i<n;i++)
    cout<<doublearr[i]<<" ";
  return 0;
}

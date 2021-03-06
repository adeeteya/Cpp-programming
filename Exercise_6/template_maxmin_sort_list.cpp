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
  int arr[]={53,76,21,9,18,11,4,32,6};
  int n=sizeof(arr)/sizeof(arr[0]);
  maxmin<int>(arr,n);
  sort<int>(arr,n);
  cout<<"The Sorted Array is\n";
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
  return 0;
}

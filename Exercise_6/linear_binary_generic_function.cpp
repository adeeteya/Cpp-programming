#include<iostream>
using namespace std;
template<typename T>
int linearsearch(T arr[],int n,T search){
  int pos=-1;
  for(int i=0;i<n;i++){
    if(arr[i]==search){
      pos=i;break;
    }
  }
  return pos;
}
template<typename T>
int binarysearch(T arr[],int low,int high,T search){
  if(high<low)
    return -1;
  int mid=low+(high-low)/2;
  if(arr[mid]=search)return mid;
  else if(arr[mid]>search)return binarysearch(arr,low,mid-1,search);
  else return binarysearch(arr,mid+1,high,search);
}
int main(){
  int arr[]={6,2,8,2,10,22,4,3,9};
  double arr2[]={7.4,3.7,2.5,2.1,3.6,7.1,5.2};
  cout<<"Element 22 is present in pos: "<<linearsearch<int>(arr,9,22);
  cout<<"\nElement 3.7 is present in pos: "<<binarysearch<double>(arr2,0,7,3.7);
  return 0;
}

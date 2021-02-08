#include<iostream>
using namespace std;
class matrice{
private:
  int m,n;
public:
  int arr[20][20];
  void readmatrice(){
    cout<<"Enter the number of rows: ";
    cin>>m;
    cout<<"Enter the number of columns: ";
    cin>>n;
    cout<<"Enter the matrice values: ";
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>arr[i][j];
  }
  void multiplymatrice(matrice a,matrice b){
    if(a.n!=b.m){
      cout<<"Matrix Multiplication not possible";
      return;
    }
    matrice result;
    result.m=a.m;result.n=b.n;
    for(int i=0;i<a.m;i++){
      for(int j=0;j<b.n;j++){
        result.arr[i][j]=0;
        for(int k=0;k<b.m;k++)
          result.arr[i][j]+=(a.arr[i][k]*b.arr[k][j]);
        }
      }
    printf("Matrix after multiplying elements (result matrix):\n");
    for(int i=0;i<result.m;i++){
      for(int j=0;j<result.n;j++)
        printf("%d\t",result.arr[i][j]);
      printf("\n");
      }
  }
};
int main(){
  matrice a,b;
  a.readmatrice();
  b.readmatrice();
  a.multiplymatrice(a,b);
  return 0;
}

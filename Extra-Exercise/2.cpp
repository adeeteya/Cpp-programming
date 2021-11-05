#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 5
int SIZE=0;
template<class T>class Matrix{
  T **data;int row,col;
  public:
  Matrix(int row,int col){this->row=row;this->col=col;
    data=new T*[row];
     for(int i=0;i<row;i++)data[i]=new T[col];
  }
  void insert(){
      cout<<"Enter the contents of the array\n";
      for(int i=0;i<row;i++)
          for(int j=0;j<col;j++)cin>>data[i][j];
  }
  void display(){
      for(int i=0;i<row;i++){
          for(int j=0;j<col;j++){
              cout<<data[i][j]<<" ";
          }
          cout<<endl;
      }
  }
};
int main(){
	int m,n;
	cout<<"Enter the no of rows: ";cin>>n;
	cout<<"Enter the no of columns: ";cin>>m;
	cout<<"Integer Matrix\n";
    Matrix<int> a(n,m);
    a.insert();
    a.display();
    cout<<"String Matrix\n";
    Matrix<string> s(n,m);
    s.insert();
    s.display();
    return 0;
}

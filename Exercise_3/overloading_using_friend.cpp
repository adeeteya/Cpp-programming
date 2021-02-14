#include<iostream>
using namespace std;
class number{
private:
  int a;
public:
  number(){a=100;}
  friend void operator ++(number &obj);
  friend void operator --(number &obj);
  void display(){
    cout<<"The value of the number is "<<a<<endl;
  }
};
void operator ++(number &obj){
  obj.a=obj.a+1;
}
void operator --(number &obj){
  obj.a=obj.a-1;
}
int main(){
  number n;
  n.display();
  ++n;
  n.display();
  --n;
  n.display();
  return 0;
}

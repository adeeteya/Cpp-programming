#include<iostream>
using namespace std;
class hello{
private:
  int data;
public:
  hello(){data=250;}
  friend void print(hello a);
};
void print(hello a){
  cout<<"Data inside the object is "<<a.data<<endl;
}
int main(){
  hello h;
  print(h);
  return 0;
}

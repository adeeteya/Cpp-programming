#include<iostream>
using namespace std;
class Number{
private:
  int n;
public:
  Number(int n=0){this->n=n;}
  ~Number(){cout<<n<<" is deleted successfully\n";}
  void display(){cout<<"The number is: "<<n<<endl;}
};
int main(){
  if(1){Number n1(1);n1.display();}
  Number n1(2);
  n1.display();
  return 0;
}

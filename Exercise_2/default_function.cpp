#include<iostream>
using namespace std;
void print_no(int n=0){
  cout<<"The value of n is "<<n<<"\n";
}
int main(){
  print_no(1);
  print_no(2);
  print_no(3);
  print_no();
  print_no(6);
  print_no();
  return 0;
}

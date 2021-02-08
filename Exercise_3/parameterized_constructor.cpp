#include<iostream>
using namespace std;
class Name{
private:
  string fname,lname;
public:
  Name(string f,string l){
    fname=f;
    l=lname;
  }
  void display(){
    cout<<fname<<" "<<lname<<endl;
  }
};
int main(){
  Name n1("Aditya","R");
  n1.display();
  Name n2("Mithun","Shankar");
  n2.display();
  return 0;
}

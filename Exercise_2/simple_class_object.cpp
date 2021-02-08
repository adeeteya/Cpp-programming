#include<iostream>
using namespace std;
class Student{
private:
  string name;
  string dept;
  int age;
  long int rollno;
public:
  Student(string n,int a,string d,long int r){
    name=n;dept=d;age=a;rollno=r;
  }
  void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Department: "<<dept<<endl;
    cout<<"Roll number: "<<rollno<<endl;
  }
};
int main(){
  Student s1("Aditya",19,"IT",195002004);
  s1.display();
  Student s2("Rahul",20,"CSE",194002012);
  s2.display();
  return 0;
}

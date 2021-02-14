#include<iostream>
using namespace std;
class Student{
private:
  string name;
  int age;
public:
  static int noofstudents;
  Student(string n,int a){
    name=n;
    age=a;
    noofstudents++;
  }
};
int Student::noofstudents=0;
int main(){
  Student s1("Aditya",19);
  Student s2("Karthik",20);
  Student s3("Rishi",15);
  cout<<"Total no of Student objects created: "<<Student::noofstudents;
  return 0;
}

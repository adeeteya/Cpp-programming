#include<iostream>
#include<stdlib.h>
using namespace std;
class Person{
private:
  string name;
  int age;
public:
  Person(string n,int a){
    name=n;
    age=a;
  }
  void * operator new(size_t size){
    cout<<"Object Created Successfully\n";
    void *p=malloc(size);
    return p;
  }
  void operator delete(void *p){
    free(p);
    cout<<"Object Deleted Successfully\n";
  }
  void display(){
    cout<<"Name: "<<name<<"\nAge: "<<age<<endl;
  }
};
int main(){
  Person *p=new Person("Aditya",19);
  p->display();
  delete p;
  return 0;
}

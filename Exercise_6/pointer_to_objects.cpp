#include<iostream>
using namespace std;
class Student{
private:
  float avgmarks;
protected:
  int rollno;
public:
  string name;
  Student(string name,int rollno,float avgmarks){
    this->name=name;this->rollno=rollno;this->avgmarks=avgmarks;
  }
  void getRollno(){cout<<"Roll no: "<<rollno<<endl;}
  void getAvgMarks(){cout<<"Average Marks: "<<avgmarks<<endl;}
};
int main(){
  Student obj("Aditya",195002004,86.5);
  Student *objptr=&obj;
  cout<<"Name: "<<objptr->name<<endl;
  objptr->getRollno();
  objptr->getAvgMarks();
  return 0;
}

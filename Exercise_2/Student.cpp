#include<iostream>
using namespace std;
class Student{
private:
  float math,physics,chemistry,english,computer,average;
  void calavg(){
    float total=math+physics+chemistry+english+computer;
    average=total/5;
  }
public:
  Student(float m,float p,float c,float e,float cc){
    math=m;physics=p;chemistry=c;english=e;computer=cc;
  }
  void displaygrade();
};
void Student::displaygrade(){
  calavg();
  cout<<"Grade: ";
  if(average>=90)cout<<"O";
  else if(average>=80)cout<<"A+";
  else if(average>=70)cout<<"A";
  else if(average>=60)cout<<"B+";
  else if(average>=50)cout<<"B";
  else if(average>=40)cout<<"C";
  else cout<<"Fail";
}

int main(){
  float p,c,m,e,cc;
  cout<<"Enter the Grades of the student\n";
  cout<<"Physics: ";cin>>p;
  cout<<"Chemistry: ";cin>>c;
  cout<<"English: ";cin>>e;
  cout<<"Math: ";cin>>m;
  cout<<"Computer: ";cin>>cc;
  Student s(m,p,c,e,cc);
  s.displaygrade();
  return 0;
}

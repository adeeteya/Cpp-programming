#include<iostream>
using namespace std;
class Person{
public:
  string name;
  int age;
  virtual void getdata(){
    cout<<"Enter Name: ";cin>>name;
    cout<<"Enter Age: ";cin>>age;
  };
  virtual void displaydata(){
    cout<<"Name: "<<name;
    cout<<"\nAge: "<<age<<endl;
  };
  virtual void bonus()=0;
};
class Admin:virtual public Person{
public:
  float salary;
  void getdata(){
    cout<<"Enter Admin Salary: ";cin>>salary;
  }
  void displaydata(){
    cout<<"Admin Salary= "<<salary<<" rs\n";
  }
  void bonus(){
    cout<<"Admin Bonus= "<<(salary*0.2)<<" rs\n";
  }
};
class Account:virtual public Person{
public:
  float salary;
  void getdata(){
    cout<<"Enter Account Salary: ";cin>>salary;
  }
  void displaydata(){
    cout<<"Account Salary= "<<salary<<" rs\n";
  }
  void bonus(){
    cout<<"Account Bonus= "<<(salary*0.6)<<" rs\n";
  }
};
class Master:public Account,public Admin{
public:
  void getdata(){
    Person::getdata();
    Account::getdata();
    Admin::getdata();
  }
  void displaydata(){
    cout<<"\nThe Details Are:\n";
    Person::displaydata();
    Account::displaydata();
    Admin::displaydata();
  }
  void bonus(){
    Account::bonus();
    Admin::bonus();
  }
};
int main(){
  Person *p=new Master();
  p->getdata();
  p->displaydata();
  p->bonus();
  return 0;
}

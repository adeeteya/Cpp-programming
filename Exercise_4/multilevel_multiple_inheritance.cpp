#include<iostream>
using namespace std;
class Animal{
protected:
  Animal(){cout<<"It is an Animal"<<endl;}
};
class Land{
protected:
  Land(){cout<<"It Lives in Land"<<endl;}
};
class Herbivore:public Animal{//multilevel inheritance
protected:
  Herbivore(){cout<<"It eats Plants"<<endl;}
};
class Elephant:public Herbivore,public Land{};//multiple inheritance
int main(){
  cout<<"Facts about Elephants:\n";
  Elephant e;
  return 0;
}

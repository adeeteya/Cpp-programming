#include<iostream>
using namespace std;
class Mammals{
public:
  void display_a(){cout<<"I am mammal"<<endl;}
};
class MarineAnimals{
public:
  void display_b(){cout<<"I am a marine animal"<<endl;}
};
class BlueWhale:public Mammals,public MarineAnimals{
public:
  void display_c(){cout<<"I belong to both the categories:Mammals as well as Marine Animals"<<endl;}
};
int main(){
  Mammals a;
  MarineAnimals b;
  BlueWhale c;
  a.display_a();
  b.display_b();
  c.display_c();
  c.display_b();
  c.display_a();
  return 0;
}

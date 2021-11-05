#include<iostream>
using namespace std;
class Fruits{
  public:
  string color;
  int price,weight;
  void Display(){
      cout<<"Color of the Fruit: "<<color<<" Price(per kg): "<<price<<"rs Weight(in gms): "<<weight<<endl;
  }
};
class Apple:public Fruits{
    public:
    Apple(){color="Red";price=120;weight=65;}
};
class Orange:public Fruits{
    public:
    Orange(){color="Orange";price=80;weight=40;}
};

int main()
{
    Apple a;
    a.Display();
    Orange g;
    g.Display();
    return 0;
}

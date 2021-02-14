#include<iostream>
using namespace std;
class shape{
protected:
  int a,b,c;
public:
  shape(int x){a=x;}
  shape(int l,int br,int h){a=l;b=br;c=h;}
  virtual void draw(){}
  void erase(){
    cout<<"\nShape Erased,Next Shape is\n";
  }
};
class circle:public shape{
public:
  circle(int x):shape(x){}
  void draw(){
    cout<<"Cirlce with a radius of: "<<a;
  }
};
class square:public shape{
public:
  square(int x):shape(x){}
  void draw(){
    cout<<"Square with a side of: "<<a;
  }
};
class triangle:public shape{
public:
  triangle(int l,int br,int h):shape(l,br,h){}
  void draw(){
    cout<<"Triangle with length= "<<a<<" breadth= "<<b<<" height= "<<c;
  }
};
int main()
{
    shape *s;
    circle c(5);
    square sqr(4);
    triangle t(2,3,5);
    s=&c;
    s->draw();
    s->erase();
    s=&sqr;
    s->draw();
    s->erase();
    s=&t;
    s->draw();
    return 0;
}

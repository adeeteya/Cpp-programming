#include<iostream>
using namespace std;
class Fruit{
public:
  static int total;
  Fruit(int a=0){total+=a;}
  int gettotal(){return total;}
};
int Fruit::total=0;
class Apples:public Fruit{
  int n;
public:
  Apples(int a):Fruit(a){n=a;}
  int getn(){return n;}
};
class Mangoes:public Fruit{
  int n;
public:
  Mangoes(int a):Fruit(a){n=a;}
  int getn(){return n;}
};
int main(){
  int no;
  cout<<"Enter no of Apples: ";cin>>no;
  Apples a(no);
  cout<<"Enter no of Mangoes: ";cin>>no;
  Mangoes m(no);
  cout<<"No of Apples present: "<<a.getn()<<endl;
  cout<<"No of Mangoes present: "<<m.getn()<<endl;
  cout<<"Total no of fruits in the basket: "<<Fruit::total;
  return 0;
}

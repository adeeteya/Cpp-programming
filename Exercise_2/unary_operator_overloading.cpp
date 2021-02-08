#include<iostream>
using namespace std;
class Distance{
private:
  float km,m;
public:
  Distance(float mts=0){
    km=mts/1000;
    m=mts;
  }
  Distance operator - (){
    km=-km;
    m=-m;
    return Distance(m);
  }
  void display(){
    cout<<"Distance in Kilometres: "<<km<<endl;
    cout<<"Distance in Metres: "<<m<<endl;
  }
};
int main(){
  float m;
  cout<<"Enter the metre's: ";cin>>m;
  Distance d1(m);
  d1.display();
  -d1;
  cout<<"Distance after negation operator:\n";
  d1.display();
  return 0;
}

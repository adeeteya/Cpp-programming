#include<iostream>
using namespace std;
class Distance{
private:
  int km,m;
public:
  Distance(int kilomts=0,int mts=0){
    km=kilomts;m=mts;
  }
  Distance operator + (Distance const &obj){
    Distance result;
    result.km=km+obj.km;
    result.m=m+obj.m;
    if(result.m>=1000){
      result.km+=(result.m/1000);
      result.m%=1000;
    }
    return result;
  }
  void display(){
    cout<<"Kilometres: "<<km<<"\n";
    cout<<"Metres: "<<m;
  }
};
int main(){
  int km,m;
  cout<<"Enter the Km's for the first Distance: ";
  cin>>km;
  cout<<"Enter the metre's for the first Distance: ";
  cin>>m;
  Distance d1(km,m);
  cout<<"Enter the Km's for the second Distance: ";
  cin>>km;
  cout<<"Enter the metre's for the second Distance: ";
  cin>>m;
  Distance d2(km,m);
  Distance result=d1+d2;
  result.display();
  return 0;
}

#include<iostream>
using namespace std;
class flight{
  int flightno,fare;
  string source,destination;
public:
  flight(int flightno,int fare,string source,string destination){
    this->flightno=flightno;this->fare=fare;
    this->source=source;this->destination=destination;
  }
  void display(){
    cout<<"Flight no: "<<this->flightno;
    cout<<"\nFare: "<<this->fare<<" rs";
    cout<<"\nSource: "<<this->source;
    cout<<"\nDestination: "<<this->destination;
  }
};
int main(){
  flight f(15623,12000,"Chennai","Delhi");
  f.display();
  return 0;
}

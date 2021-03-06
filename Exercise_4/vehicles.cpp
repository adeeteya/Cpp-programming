#include<iostream>
using namespace std;
class Vehicle{
  float mileage;
  int price;
public:
  Vehicle(float mileage,int price){this->mileage=mileage;this->price=price;}
  void display(){cout<<"Mileage: "<<mileage<<" kmpl"<<"\tPrice: "<<price<<" rs\n\n";}
};
class Car:public Vehicle{
  int warranty,seatingcapacity,ownershipcost;
  string fueltype;
public:
  Car(int warranty,int seatingcapacity,int ownershipcost,string fueltype,float mileage,int price)
  :Vehicle(mileage,price){
    this->warranty=warranty;this->seatingcapacity=seatingcapacity;this->ownershipcost=ownershipcost;
    this->fueltype=fueltype;
  }
  void display(){
    cout<<"Warranty: "<<warranty<<" Years"
    <<"\tSeatingcapacity: "<<seatingcapacity<<" people\n"
    <<"Ownership cost: "<<ownershipcost<<" rs"
    <<"\tFuel type: "<<fueltype<<endl;Vehicle::display();
  }
};
class Bike:public Vehicle{
  int noofcylinders,noofgears;
  string coolingtype,wheeltype;
  float fueltanksize;
public:
  Bike(int noofcylinders,int noofgears,string coolingtype,string wheeltype,float fueltanksize,float mileage,int price)
  :Vehicle(mileage,price){
    this->noofcylinders=noofcylinders;this->noofgears=noofgears;
    this->coolingtype=coolingtype;this->wheeltype=wheeltype;
    this->fueltanksize=fueltanksize;
  }
  void display(){
    cout<<"No of cylinders: "<<noofcylinders
    <<"\tNo of Gears: "<<noofgears<<endl
    <<"Cooling Type: "<<coolingtype
    <<"\tWheel type: "<<wheeltype<<endl
    <<"Fueltank size:"<<fueltanksize<<" inches\n";Vehicle::display();
  }
};
class Audi:public Car{
  string modeltype;
public:
  Audi(string modeltype,int warranty,int seatingcapacity,int ownershipcost,string fueltype,float mileage,int price)
  :Car(warranty,seatingcapacity,ownershipcost,fueltype,mileage,price)
  {this->modeltype=modeltype;}
  void display(){cout<<"Modeltype: "<<modeltype<<endl;Car::display();}
};
class Ford:public Car{
  string modeltype;
public:
  Ford(string modeltype,int warranty,int seatingcapacity,int ownershipcost,string fueltype,float mileage,int price)
  :Car(warranty,seatingcapacity,ownershipcost,fueltype,mileage,price)
  {this->modeltype=modeltype;}
  void display(){cout<<"Modeltype: "<<modeltype<<endl;Car::display();}
};
class Bajaj:public Bike{
  string maketype;
public:
  Bajaj(string maketype,int noofcylinders,int noofgears,string coolingtype,string wheeltype,float fueltanksize,float mileage,int price)
  :Bike(noofcylinders,noofgears,coolingtype,wheeltype,fueltanksize,mileage,price)
  {this->maketype=maketype;}
  void display(){cout<<"Maketype: "<<maketype<<endl;Bike::display();}
};
class TVS:public Bike{
  string maketype;
public:
  TVS(string maketype,int noofcylinders,int noofgears,string coolingtype,string wheeltype,float fueltanksize,float mileage,int price)
  :Bike(noofcylinders,noofgears,coolingtype,wheeltype,fueltanksize,mileage,price)
  {this->maketype=maketype;}
  void display(){cout<<"Maketype: "<<maketype<<endl;Bike::display();}
};
int main(){
  Audi a("Audi A6 sports",5,5,9500,"Petrol",8.5,4500000);a.display();
  Ford f("Ford Fiesta Classic",2,4,5000,"Diesel",21.5,800000);f.display();
  Bajaj b("Bajaj Pulsar 150",3,6,"liquid","alloys",550,45,80000);b.display();
  TVS t("Tvs Apache rtr",4,5,"oil","spokes",770,30,100000);t.display();
  return 0;
}

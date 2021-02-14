#include<iostream>
using namespace std;
class Area{
private:
  float area;
public:
  Area(){area=0;}
  Area(int s){area=s*s;}
  Area(int l,int b){area=l*b;}
  void display(){cout<<"The area is: "<<area<<"\n\n";}
};
int main(){
  int choice=1;
  while(choice==1||choice==2){
    cout<<"Find Area for\n1.Square\n2.Rectangle\nAnything else to quit: ";
    cin>>choice;
    if(choice==1){
      int s;
      cout<<"Enter The side: ";
      cin>>s;Area a(s);a.display();
    }
    else if(choice==2){
      int l,b;
      cout<<"Enter The length: ";cin>>l;
      cout<<"Enter The breadth: ";cin>>b;
      Area a(l,b);a.display();
    }
  }
}

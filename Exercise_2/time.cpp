#include<iostream>
#include<string>
using namespace std;
class time{
private :
  int hours=0,minutes=0,seconds=0;
public:
  void displaytime();
};

void time::displaytime(){
  string display;
  if(seconds>60){
    minutes+=(seconds/60);
    seconds%=60;
  }
  if(minutes>60){
    hours+=(minutes/60);
    minutes%=60;
  }
  if(hours<10)
    display="0"+to_string(hours)+":";
  else
    display=to_string(hours)+":";
  if(minutes<10)
    display+="0"+to_string(minutes)+":";
  else
    display+=to_string(minutes)+":";
  if(seconds<10)
    display+="0"+to_string(seconds);
  else
    display+=to_string(seconds);
  cout<<"The time is = "<<display;
}

int main(){
  time obj;
  cout<<"Enter time: \n";
  cout<<"Hours? ";
  cin>>obj.hours;
  cout<<"Minutes? ";
  cin>>obj.minutes;
  cout<<"Seconds? ";
  cin>>obj.seconds;
  obj.displaytime();
  return 0;
}

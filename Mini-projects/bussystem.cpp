#include<iostream>
#include<string>
using namespace std;
static int noofbus,n=0,choice;
int menu();

class time{
public:
  int minutes,hours;
  string meridiem;
public:
  void entertime();
  void displaytime();
};

void time::entertime(){
  string temp;
  cout<<"\n\n\t\tEnter time in HH:MM format(24-hour): ";
  cin>>temp;
  hours=stoi(temp.substr(0,2));
  minutes=stoi(temp.substr(3,2));
  if(hours>12 && hours<24){
    hours=hours-12;
    meridiem="PM";
  }
  else
    meridiem="AM";
}
void time::displaytime(){
  string temp;
  if(hours<10)
    temp="0"+to_string(hours)+":";
  else
    temp=to_string(hours)+":";
  if(minutes<10)
    temp+="0"+to_string(minutes);
  else
    temp+=to_string(minutes);
  cout<<temp<<" "<<meridiem;
}

class buses{
public:
  int busno;
  time arrival,depart;
  string from,to,seat[8][4],driver;
public:
  void allotseats();
}bus[20];

void addbus(){
  if(n>=noofbus){
    cout<<"\aMax no of buses reached!,Can't add any more buses";
    system("pause");
    menu();
    return;
  }
  cout<<"\n\n\t\tBus no: ";
  cin>>bus[n].busno;
  cout<<"\t\tArrival time";
  bus[n].arrival.entertime();
  cout<<"\t\tDeparture time";
  bus[n].depart.entertime();
  cout<<"\t\tDestination";
  cout<<"\n\t\tFrom: ";
  cin>>bus[n].from;
  cout<<"\t\tTo: ";
  cin>>bus[n].to;
  cout<<"\t\tDriver name: ";
  cin>>bus[n].driver;
  for(int i=0;i<8;i++)
    for(int j=0;j<4;j++)
      bus[n].seat[i][j]="EMPTY";
  bus[n].allotseats();
  n+=1;
  menu();
}

void buses::allotseats(){
  int seatno;
  allotscreen:
  system("cls");
  cout<<"\n\tEnter seat no(Enter 0 to go back to main menu): ";
  cin>>seatno;
  if(seatno==0)
    return;
  if(seatno>32){
    cout<<"Invalid number, ";system("pause");
    goto allotscreen;
  }
  else{
    if(seat[seatno/4][(seatno%4)-1]=="EMPTY"){
      cout<<"\n\tEnter name: ";
      cin>>seat[seatno/4][(seatno%4)-1];
      goto allotscreen;
    }
    else{
      cout<<"\a\nSeat is Already Reserved, ";
      system("pause");
      goto allotscreen;
    }
  }
}

void allotseat(){
  int busn,k=0,check=0,seatno;
  cout<<"Enter bus no: ";
  cin>>busn;
  while(k<n){
    if(bus[k].busno==busn){
      check=1;
      break;
    }
    k++;
  }
  if(check==0){
    cout<<"\a\nBus not found, ";
    system("pause");
    system("cls");
    allotseat();
  }
  else{
    seatscreen:
    cout<<"\n\tEnter seat no(Enter 0 to go back to main menu): ";
    cin>>seatno;
    if(seatno==0){
      menu();
      return;
    }
    if(seatno>32){
      cout<<"Invalid number, ";system("pause");
      goto seatscreen;
    }
    else{
      if(bus[k].seat[seatno/4][(seatno%4)-1]=="EMPTY"){
        cout<<"\n\tEnter name: ";
        cin>>bus[k].seat[seatno/4][(seatno%4)-1];
        goto seatscreen;
      }
      else{
        cout<<"\a\nSeat is Already Reserved, ";
        system("pause");
        goto seatscreen;
      }
  }
}
}

void checkbus(){
  int busn,k=0,check=0;
  cout<<"Enter bus no: ";
  cin>>busn;
  while(k<n){
    if(bus[k].busno==busn){
      check=1;
      break;
    }
    k++;
  }
  if(check==0){
    cout<<"\a\nBus not found, ";
    system("pause");
    checkbus();
  }
  else{
    system("cls");
    for(int r=0;r<80;r++)cout<<"*";
    cout<<"\n\t\tBus no: \t"<<bus[k].busno
    <<"\nDriver: \t"<<bus[k].driver<<"\t\tArrival time: \t";
    bus[k].arrival.displaytime();
    cout<<"\tDeparture time:";bus[k].depart.displaytime();
    cout<<"\nFrom: \t\t"<<bus[k].from<<"\t\tTo: \t\t"<<
    bus[k].to<<"\n";
    for(int r=0;r<80;r++)cout<<"*";
    cout<<endl;
    for(int i=0;i<8;i++){
      for(int j=0;j<4;j++){
        cout.width(10);
        cout<<"Seat no "<<(4*i+j+1)<<":"<<bus[k].seat[i][j]<<"\t";
      }
      cout<<endl;
      }
  }
  cout<<endl;
  system("pause");
  menu();
}

int menu(){
  system("cls");
  cout<<"\n\n\t\tEnter your choice: ";
  cout<<"\n\n\t\t1.Add a Bus";
  cout<<"\n\n\t\t2.Allot a seat: ";
  cout<<"\n\n\t\t3.Check Bus Details";
  cout<<"\n\n\t\t4.Exit\t";
  cin>>choice;
  switch(choice){
    case 1: addbus();break;
    case 2: allotseat();break;
    case 3: checkbus();break;
    case 4: exit(0);break;
    default:  cout<<"\nInvalid Input, ";system("pause");menu();
  }
  return 0;
}

int main(){
  menu();
}

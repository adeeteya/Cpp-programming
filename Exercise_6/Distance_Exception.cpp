#include<iostream>
using namespace std;
class Exception{
public:
  Exception(){cerr<<"No Argument Entered\n";}
  Exception(char e){cerr<<"Inches not a number Exception\n";}
  Exception(string e){cerr<<"Nondigit Character Exception\n";}
  Exception(out_of_range e){cerr<<e.what();}
};
class Distance{
int feet;
int inch;
public:
    Distance(){throw 404;}
    Distance(int i){
      if(i<0)throw out_of_range("Inches Out of Range Exception\n");
      else{
        feet=i/12;
        inch=i%12;cout<<"(No error)Feet: "<<feet<<"\tInches: "<<inch;
      }
    }
    Distance(int f,int i){
      if(i>=12)throw out_of_range("(Double Argument)Inches Out of Range Exception\n");
      else{feet=f;inch=i;cout<<"No error Ocurred here\n";}
    }
    Distance(int f,char i){throw i;}
    Distance(char e){throw e;}
    Distance(string e){throw e;}
};
int main(){
  try{Distance d(-6);}catch(out_of_range e){Exception m(e);}
  try{Distance d;}catch(int i){Exception m;}
  try{Distance d('k');}catch(char c){Exception m(c);}
  try{Distance d("hello");}catch(string s){Exception m(s);}
  try{Distance d(11,15);}catch(out_of_range e){Exception m(e);}
  try{Distance d(150);}catch(...){cerr<<"Unknown Exception Ocurred";}
  return 0;
}

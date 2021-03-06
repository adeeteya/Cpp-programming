#include<iostream>
#include<math.h>
using namespace std;
class Complex{
    int real,imag;
public:
    Complex(){real=0;imag=0;}
    void input(){
      cout<<"Enter the real part: ";cin>>real;
      cout<<"Enter the imaginary part: ";cin>>imag;
    }
    Complex operator + (Complex const &obj){
       Complex res;
       res.real=real+obj.real;
       res.imag=imag+obj.imag;
       return res;
    }
    Complex operator -(Complex const &obj){
      Complex res;
      res.real=real-obj.real;
      res.imag=imag-obj.imag;
      return res;
    }
    Complex operator *(Complex const &obj){
      Complex res;
      res.real=(real*obj.real)-(imag*obj.imag);
      res.imag=(real*obj.imag)+(imag*obj.real);
      return res;
    }
    Complex operator /(Complex const &obj){
      Complex res;
      res.real=(((real)*(obj.real))+((imag)*(obj.imag)))/(pow(obj.real,2)+pow(obj.imag,2));
      res.imag=(((obj.real)*(imag))-((real)*(obj.imag)))/(pow(obj.real,2)+pow(obj.imag,2));
      return res;
    }
    void display(){
      cout<<real<<" + "<<imag<<"i"<<endl;
    }
};

int main()
{
  Complex c1,c2,result;
  cout<<"Enter Complex no 1\n";c1.input();
  cout<<"Enter Complex no 2\n";c2.input();
  result=c1+c2;
  cout<<"The sum of the Two complex numbers is: ";
  result.display();
  result=c1-c2;
  cout<<"The Difference of the Two complex numbers is: ";
  result.display();
  result=c1*c2;
  cout<<"The multiplication of the Two complex numbers is: ";
  result.display();
  result=c1/c2;
  cout<<"The Division of the Two complex numbers is: ";
  result.display();
  return 0;
}

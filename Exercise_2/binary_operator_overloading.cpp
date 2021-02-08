#include<iostream>
using namespace std;
class Complex{
private:
    int real,imag;
public:
    Complex(){
      real=0;imag=0;
    }
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
    void display(){
      cout<<real<<" + i"<<imag<<endl;
    }
};

int main()
{
  Complex c1,c2;
  cout<<"Enter Complex no 1\n";c1.input();
  cout<<"Enter Complex no 2\n";c2.input();
  Complex result=c1+c2;
  cout<<"The sum of the Two complex numbers is: ";
  result.display();
}

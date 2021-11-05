#include<iostream>
#include<conio.h>
#include<stdexcept>
using namespace std;
#define MAX 5
class Stack{
	int top;
public:
	int a[MAX];
	Stack(){top=-1;}
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};
bool Stack::push(int x)
{
	if(top>=(MAX-1)){
		throw overflow_error("Stack Overflow Error");
		//cout<<"Stack Overflow";
		return false;
	}
	else{
		a[++top]=x;
		cout<<x<<" pushed into stack\n";
		return true;
	}
}
int Stack::pop()
{
	if(top<0){
		throw underflow_error("Stack Underflow Error");
		//cout<<"Stack Underflow";
		return 0;
	}
	else{
		int x=a[top--];
		return x;
	}
}
int Stack::peek()
{
	if(top<0){
		cout<<"Stack is Empty";
		return 0;
	}
	else{
		int x=a[top];
		return x;
	}
}
bool Stack::isEmpty()
{
	return(top<0);
}

int main()
{
	class Stack s;
  int choice,data;
  while(1){
    cout<<"\n";
    cout<<"\t\tMain Menu\n";
    cout<<"1.Push\n2.Pop\n3.Peek\n4.Exit\n";
    cout<<"Enter your choice: ";cin>>choice;
    switch(choice){
      case 1:cout<<"Enter value to push: ";cin>>data;try{
		s.push(data);
	  }catch(overflow_error e){
    cout<<e.what()<<endl;
  	}cout<<"Press any key to continue";getch();break;
      case 2:try{cout<<s.pop()<<" Popped from stack\n";}catch(underflow_error e){cout<<e.what()<<endl;}
      cout<<"Press any key to continue";getch();break;
      case 3:cout<<s.peek()<<" is on top of the stack\n";cout<<"Press any key to continue";getch();break;
      case 4:exit(0);break;
      default:cout<<"Invalid Input,Press any key to try again";getch();
    }
  }
	return 0;
}

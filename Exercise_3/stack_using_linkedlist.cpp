#include<iostream>
using namespace std;
class node{
private:
  int data;
  node *next;
  friend class stack;
};
class stack{
private:
  node *top;
public:
  stack(){
    top=NULL;
  }
  void push(int x){
    node *temp=new node();
    temp->data=x;
    temp->next=top;
    top=temp;
    cout<<top->data<<" has been inserted into the stack\n";
  }
  void pop(){
    if(top==NULL)
      cout<<"Underflow\n";
    else{
      node *temp=top;
      top=top->next;
      cout<<temp->data<<" has been removed from the stack\n";
      delete(temp);
    }
  }
  void peek(){
    if(top==NULL)
      cout<<"Underflow\n";
    else
      cout<<"The top of the stack is: "<<top->data<<endl;
  }
};
int main(){
  stack s;int choice,data;
  while(1){
    cout<<"\n1.Push\n2.Pop\n3.Peek\nPress anything else to Exit";
    cout<<"\nEnter your choice: ";cin>>choice;
    switch(choice){
      case 1:cout<<"Enter data to be pushed into the stack: ";
      cin>>data;s.push(data);break;
      case 2:s.pop();break;
      case 3:s.peek();break;
      default:return 0;
    }
  }
}

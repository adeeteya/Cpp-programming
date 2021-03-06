#include<iostream>
#define SIZE 5
using namespace std;
class item{
public:
  string name;
  int stock;
};
class STACK
{
  item s[SIZE];
  int top;
public:
  STACK(){top=-1;}
  void push(string,int);
  //void pop();
  int isEmpty(){if(top==-1)return 1;else return 0;}
  int isFull(){if(top==(SIZE-1))return 1;else return 0;}
  void display();
  void update(int);
};

void STACK::push(string name,int n){
  if(isFull()){
    cout<<"The Inventory is Full Unable to Add items\n";
    return;
  }
  ++top;
  s[top].name=name;s[top].stock=n;
}

/*void STACK::pop(){
  if(isEmpty()){
  }
  --top;
}*/

void STACK::display(){
    if(top==-1){
      cout<<"The inventory is Empty!";return;
    }
    int i;
    cout<<"The items in the inventory are: \n";
    for(i=0;i<=top;i++)
        cout<<i+1<<" Item Name: "<<s[i].name<<" Stock Remaining: "<<s[i].stock<<endl;
    cout<<endl;
}
void STACK::update(int k){
  if(k>top+1){
    cout<<"Invalid inventory index,Please try again!\n";return;
  }
  cout<<"Enter new stock count for "<<s[k-1].name<<" :";
  cin>>s[k-1].stock;
  cout<<"Stock count updated successfully\n";
}

int main(){
  STACK stk;
  string tempname;
  int choice,tempstock;
  while(1){
    cout<<"\n\t\tMain Menu\n";
    cout<<"1.Add item\n2.Display the Inventory\n3.Update item\n4.Exit\n";
    cout<<"Enter your choice: ";cin>>choice;
    switch(choice){
      case 1:cout<<"Enter the name of the item: ";cin>>tempname;
      cout<<"Enter the stock count: ";cin>>tempstock;
      stk.push(tempname,tempstock);break;
      case 2:stk.display();break;
      case 3:cout<<"Enter the inventory number to be modified: ";cin>>tempstock;
      stk.update(tempstock);break;
      case 4:return 0;break;
      default:cout<<"Invalid Input,Try Again";
    }
  }
  return 0;
}

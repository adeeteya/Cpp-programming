#include<iostream>
using namespace std;
#define MAXSIZE 5
class node{
public:
  string name;
  int rno;
  node *next;
  static int size;
}*root;
int node::size=0;
void display(){
  if(root->size==0){
    cout<<"No Reservations made!!\n";
    return;
  }
  node *temp=root;
  while(temp!=NULL){
    cout<<"\nName: "<<temp->name<<endl;
    cout<<"Reservation No: "<<temp->rno<<endl;
    cout<<"Ticket Status: "<<((temp->rno<MAXSIZE)?"Confirmed":"Waiting List")<<endl;
    temp=temp->next;
  }
}
void insert(){
  node *newNode=new node;
  cout<<"Enter your Name: ";cin>>newNode->name;
  if(root->size==0)root=newNode;
  else{
    node *temp=root;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=newNode;
  }
  newNode->rno=++root->size;newNode->next=NULL;
  if(root->size>=MAXSIZE){
    cout<<"Booking Full,Adding you to the waiting list!!\n";
    cout<<"Position in the Waiting List: "<<(root->size-MAXSIZE)+1;
  }
  else
    cout<<"Booking Confirmed\n";
}
void cancel(){
  if(root->size==0){
    cout<<"No reservations Available to cancel";return;
  }
  int rno;
  cout<<"Enter Reservation no to cancel: ";cin>>rno;
  if(root->size<rno || rno<0){
    cout<<"Invalid Reservation number,Exiting to Main Menu\n";return;
  }
  else{
    node *temp=root;node *delnode;
    if(root->next==NULL&&root->rno==rno){
      delnode=root;root=NULL;
    }
    else if(root->rno==rno){
      delnode=root;root=root->next;
    }
    else{
      while(temp!=NULL){
        if(temp->next->rno==rno){
          delnode=temp->next;
          temp->next=delnode->next;

          break;
        }
        temp=temp->next;
      }
    }
    delete delnode;
    temp=root;int i=1;
    while(temp!=NULL){
      temp->rno=i;temp=temp->next;i++;
    }root->size=i-1;
  }
}
int main(){
  int choice;
  while(1){
    cout<<"\n\t\tMain Menu\n";
    cout<<"1.Reserve A ticket\n2.Cancel Reservation\n3.Display Reservations\n4.Exit\n";
    cout<<"Enter your choice: ";cin>>choice;
    switch(choice){
      case 1:insert();break;
      case 2:cancel();break;
      case 3:display();break;
      case 4:return 0;break;
      default:cout<<"Invalid Input,Try Again";
    }
  }
  return 0;
}

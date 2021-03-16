#include<iostream>
using namespace std;
int SIZE=0;
template<class T>class Node{
public:
  T data;
  Node *next;
};
template<class T>
class linkedlist{
  Node<T> *root;
public:
  linkedlist(){root=NULL;}
  void insert(int pos,T data){
    if(SIZE<pos || pos<0){cout<<"Please Enter a valid position\n";return;}
    Node<T> *newnode=new Node<T>;
    newnode->data=data;
    if(root==NULL){newnode->next=NULL;root=newnode;}
    else{
      if(pos==0){newnode->next=root;root=newnode;}
      else{
        Node<T> *tmp=root;int i=0;
        while(tmp!=NULL){
          if(i==pos-1){
            newnode->next=tmp->next;
            tmp->next=newnode;break;
          }
          tmp=tmp->next;i++;
        }
      }
    }
    SIZE++;
  }
  void remove(int pos){
    if(SIZE<=pos || pos<0){cout<<"Please Enter a valid position\n";return;}
    if(root==NULL){cout<<"The Linked List is Empty\n";return;}
    Node<T> *tmp=root,*delnode;int i=0;
    if(pos==0){delnode=root;root=root->next;}
    else{
      while(tmp!=NULL){
        if(i==pos-1){
          delnode=tmp->next;
          tmp->next=delnode->next;break;
        }
        tmp=tmp->next;i++;
      }
    }
    delete delnode;
    SIZE--;
  }
  void display(){
    Node<T> *tmp=root;
    while(tmp!=NULL){
      cout<<tmp->data<<endl;
      tmp=tmp->next;
    }
  }
};
int main(){
  cout<<"The numbers are:\n";
  linkedlist<int> l;
  l.insert(0,5);l.insert(0,3);l.insert(0,9);
  l.insert(1,2);l.insert(0,99);l.insert(4,999);
  l.remove(0);l.remove(1);l.display();
  cout<<"\nThe names in the list are:\n";
  linkedlist<string> namelist;
  namelist.insert(0,"Aditya");namelist.insert(1,"Ajit");
  namelist.insert(0,"Abhishek");namelist.insert(3,"Rohit");
  namelist.remove(2);namelist.display();
  return 0;
}

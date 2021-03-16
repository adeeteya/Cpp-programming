#include<iostream>
using namespace std;
class client{
public:
  string name;
  int gender;
  void setDetails(){
    cout<<"Enter the name of the client: ";cin>>name;
    gender=1;//default
  }
};
class Node{
public:
  int ID,height;client c;
  Node *left,*right;
}*root;

class{
public:
  Node *q[100];
  int front,rear;
  int qisEmpty(){
    if(front==-1)return 1;
    else return 0;
  }
  void push(Node *temp){
    if(qisEmpty())front++;
    q[++rear]=temp;
  }
  void pop(){
    if(qisEmpty())return;
    front++;if(front>rear)front=rear=-1;
  }
}queue;
int max(int a,int b){return (a>b)?a:b;}
int height(Node *temp){
  if(temp==NULL)return 0;
  return temp->height;
}
Node *newNode(int k){
  Node *temp=new Node();
  temp->c.setDetails();
  temp->ID=k;temp->height=1;
  temp->left=temp->right=NULL;
  return temp;
}
Node *rightRotate(Node *y){
  Node *x=y->left;
  Node *temp=x->right;
  x->right=y;
  y->left=temp;
  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;
  return x;
}
Node *leftRotate(Node *x){
  Node *y=x->right;
  Node *temp=y->left;
  y->left=x;
  x->right=temp;
  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;
  return y;
}
int getBalance(Node *temp){
  if(temp==NULL)return 0;
  return height(temp->left)-height(temp->right);
}
Node *insert(Node *temp,int k){
  if(temp==NULL)return newNode(k);
  if(k<temp->ID)temp->left=insert(temp->left,k);
  else if(k>temp->ID)temp->right=insert(temp->right,k);
  else return temp;
  temp->height=max(height(temp->left),height(temp->right))+1;
  int bal=getBalance(temp);
  if(bal>1){
    if(k<temp->left->ID)return rightRotate(temp);
    else if(k>temp->left->ID){
      temp->left=leftRotate(temp->left);
      return rightRotate(temp);
    }
  }
  else if(bal<-1){
    if(k>temp->right->ID)return leftRotate(temp);
    else if(k<temp->right->ID){
      temp->right=rightRotate(temp->left);
      return leftRotate(temp);
    }
  }
  return temp;
}

void Update(Node *temp,int k){
  if(temp==NULL)return;
  if(k<temp->ID)return Update(temp->left,k);
  else if(k>temp->ID)return Update(temp->right,k);
  else{
    temp->c.gender=0;
    cout<<"Gender for the key Updated Successfully\n";return;
  }
}
void FindDiff(Node *temp,int k){
  int nmen=0,nwom=0;
  if(temp==NULL){cout<<"No Node less than "<<k<<endl;return;}
  queue.push(temp);
  while(!queue.qisEmpty()){
    temp=queue.q[queue.front];queue.pop();
    if(k>temp->ID){(temp->c.gender==0)?nmen++:nwom++;}
    if(temp->left!=NULL)queue.push(temp->left);
    if(temp->right!=NULL)queue.push(temp->right);
  }
  queue.front=queue.rear=-1;
  cout<<"Difference between no of women and men: "<<nwom-nmen<<endl;return;
}
void display(Node *temp){
  if(temp==NULL)return;
  cout<<temp->ID<<"\t"<<temp->c.name<<"\t";
  (temp->c.gender==0)?cout<<"M\n":cout<<"F\n";
  display(temp->left);
  display(temp->right);
}
int main(){
  int choice,k;queue.front=queue.rear=-1;
  while(1){
    cout<<"\n\t\tMain Menu\n1.Add Client\n2.Update Client to a man\n3.Difference between no of women and men\n4.Display\n5.Exit\n";
    cout<<"Enter your choice: ";cin>>choice;
    switch(choice){
      case 1:cout<<"Enter the id: ";cin>>k;root=insert(root,k);break;
      case 2:cout<<"Enter the id to be updated: ";cin>>k;Update(root,k);break;
      case 3:cout<<"Enter the id to find Difference: ";cin>>k;FindDiff(root,k);break;
      case 4:display(root);break;
      case 5:exit(0);break;
      default:cout<<"Invalid Input,Try Again\n";
    }
  }
  return 0;
}

#include<iostream>
using namespace std;
class Node{
public:
  int key,height;
  Node *left,*right;
}*root;
int max(int a,int b){return (a>b)?a:b;}
int height(Node *temp){
  if(temp==NULL)return 0;
  return temp->height;
}
Node *newNode(int key){
  Node *temp=new Node();
  temp->key=key;temp->height=1;
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
Node *insert(Node *temp,int key){
  if(temp==NULL)return newNode(key);
  if(key<temp->key)temp->left=insert(temp->left,key);
  else if(key>temp->key)temp->right=insert(temp->right,key);
  else return temp;
  temp->height=max(height(temp->left),height(temp->right))+1;
  int bal=getBalance(temp);
  if(bal>1){
    if(key<temp->left->key)return rightRotate(temp);
    else if(key>temp->left->key){
      temp->left=leftRotate(temp->left);
      return rightRotate(temp);
    }
  }
  else if(bal<-1){
    if(key>temp->right->key)return leftRotate(temp);
    else if(key<temp->right->key){
      temp->right=rightRotate(temp->left);
      return leftRotate(temp);
    }
  }
  return temp;
}
Node *nodeWithMinValue(Node *temp){
  Node *current=temp;
  while(current->left!=NULL)current=current->left;
  return current;
}

Node *deleteNode(Node *root,int key){
  if(root==NULL)return root;
  if(key<root->key)root->left=deleteNode(root->left,key);
  else if(key>root->key)root->right=deleteNode(root->right,key);
  else {
    if((root->left==NULL)||(root->right==NULL)){
      Node *temp=root->left?root->left:root->right;
      if(temp==NULL){temp=root;root=NULL;}
      else *root=*temp;
      free(temp);
    }
    else{
      Node *temp=nodeWithMinValue(root->right);
      root->key=temp->key;
      root->right=deleteNode(root->right,temp->key);
    }
  }
  if(root==NULL)return root;
  root->height=1+max(height(root->left),height(root->right));
  int bal=getBalance(root);
  if(bal>1){
    if(getBalance(root->left)>=0)return rightRotate(root);
    else{
      root->left=leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if(bal<-1){
    if(getBalance(root->right)<=0)return leftRotate(root);
    else{
      root->right=rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}
void inorder(Node *temp){
  if(temp==NULL)return;
  inorder(temp->left);
  cout<<temp->key<<" ";
  inorder(temp->right);
}
int main(){
  int choice,key;
  while(1){
    cout<<"\n\t\tMain Menu\n1.Insert\n2.Delete\n3.Inorder-Display\n4.Exit\n";
    cout<<"Enter your choice: ";cin>>choice;
    switch(choice){
      case 1:cout<<"Enter the key: ";cin>>key;root=insert(root,key);break;
      case 2:cout<<"Enter the key to be deleted: ";cin>>key;root=deleteNode(root,key);break;
      case 3:inorder(root);break;
      case 4:exit(0);break;
      default:cout<<"Invalid Input,Try Again\n";
    }
  }
  return 0;
}

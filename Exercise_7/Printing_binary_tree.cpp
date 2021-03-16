#include<iostream>
using namespace std;
class Node{
public:
  int key;
  Node *left,*right;
}*root;
Node *insert(int key,Node *temp){
  if(temp==NULL){
    temp=new Node();
    temp->key=key;
    temp->left=temp->right=NULL;
    if(root==NULL)root=temp;
  }
  else if(key<=temp->key)
    temp->left=insert(key,temp->left);
  else
    temp->right=insert(key,temp->right);
  return temp;
}
void preorder(Node *temp){
if(temp==NULL)return ;
cout<<temp->key<<" ";
preorder(temp->left);
preorder(temp->right);
}
void inorder(Node *temp){
  if(temp==NULL)return ;
  inorder(temp->left);
  cout<<temp->key<<" ";
  inorder(temp->right);
}
void postorder(Node *temp){
  if(temp==NULL)return ;
  postorder(temp->left);
  postorder(temp->right);
  cout<<temp->key<<" ";
}
int main(){
  int n,key;
  cout<<"Enter the no of items in the tree: ";cin>>n;
  cout<<"Enter the elements of the tree\n";
  for(int i=0;i<n;i++){
    cin>>key;
    insert(key,root);
  }
  cout<<"Preorder: ";preorder(root);
  cout<<"\nInorder: ";inorder(root);
  cout<<"\nPostorder: ";postorder(root);
  return 0;
}

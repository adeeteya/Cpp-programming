#include<iostream>
using namespace std;
class treenode
{
public:
	int key;
	treenode *left,*right;
  friend class SplayTree;
};
treenode *newNode(int key)
{
	treenode *temp=new treenode();
	temp->key=key;
	temp->left=temp->right=NULL;
	return temp;
}

treenode *rightRotate(treenode *x)
{
	treenode *y=x->left;
	x->left=y->right;
	y->right=x;
	return y;
}

treenode *leftRotate(treenode *x)
{
	treenode *y=x->right;
	x->right=y->left;
	y->left=x;
	return y;
}

treenode *splay(treenode *root,int key)
{
	//if root is null or key is present in root
	if(root==NULL||root->key==key)return root;
	if(root->key>key)//if key lies in the left subtree
	{
		//If key is not in the tree,then return root
		if(root->left==NULL)return root;
		if(root->left->key>key)//Zig-Zig
		{
			//Recursively bring the key as the root here
			root->left->left=splay(root->left->left,key);
			root=rightRotate(root);//the first rotation for the new root
		}
		else if(root->left->key<key)//Zig-Zag
		{
			//Recursively bring the key as the root here
			root->left->right=splay(root->left->right,key);
			//The first rotation for root->left
			if(root->left->right!=NULL)root->left=leftRotate(root->left);
		}
		//second rotation
		return (root->left==NULL)?root:rightRotate(root);
	}
	else//The key lies in theright subtree
	{
		//If the Key is not in tree,then return the root
		if(root->right==NULL)return root;
		if(root->right->key>key)//Zag-Zig
		{
			//Bring the key as root of right-left
			root->right->left=splay(root->right->left,key);
			//Do the first rotation for root->right
			if(root->right->left!=NULL)root->right=rightRotate(root->right);
		}
		else if(root->right->key<key)//Zag-Zag
		{
			// Bring the key as root of right right
			root->right->right=splay(root->right->right,key);
			root=leftRotate(root);//first rotation
		}
		//second rotation
		return (root->right==NULL)?root:leftRotate(root);
	}
}
treenode *insertnode(treenode *root,int k)
{
    if(root==NULL)return newNode(k);//If the tree is empty
    root=splay(root,k);//Bring the closest leaf node to the root
    if(root->key==k)return root;//If key is already present,then return
    treenode *newnode=newNode(k);//Else create a new node
    //If root's key is greater,make root as right child of newnode and copy the left child of root to newnode
    if(root->key>k)
    {
        newnode->right=root;
        newnode->left=root->left;
        root->left=NULL;
    }
    //If root's key is smaller,make root as left child of newnode and copy the right child of root to newnode
    else
    {
        newnode->left=root;
        newnode->right=root->right;
        root->right=NULL;
    }
    return newnode;//newnode becomes the new root
}
void preOrder(treenode *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->key<<" ";
		preOrder(temp->left);
		preOrder(temp->right);
	}
}
class SplayTree{
  treenode *root;
public:
  SplayTree(){root=NULL;}
	void insert(){
		int key;
		cout<<"Enter the key to insert: ";cin>>key;
		root=insertnode(root,key);
		cout<<"The key is inserted sucessfully\n";
	}
  void display(){
    cout<<"The contents of the tree are\n";
    preOrder(root);
  }
	void search(){
		int key;
		cout<<"Enter the key to search: ";cin>>key;
		root=splay(root,key);
		if(root->key==key)cout<<"Key Found\n";
		else cout<<"Key not found\n";
	}
};

int main()
{
	int choice=0;
	SplayTree t;
  while(1){
    cout<<"\nMain menu\n1.Insert\n2.Search\n3.Display\n4.Exit\nEnter your choice: ";cin>>choice;
    switch(choice){
      case 1:t.insert();break;
      case 2:t.search();break;
      case 3:t.display();break;
      case 4:exit(0);
      default:cout<<"Invalid Input,Try Again\n";
    }
  }
	return 0;
}

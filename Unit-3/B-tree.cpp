#include<iostream>
using namespace std;

class BTreeNode
{
	int *keys;// An array of maximum m-1 keys
	int m;//Degree of b-tree.also the minimum no of children a tree can have
	BTreeNode **C;//Pointer array of the children
	int n;//Current number of keys present
	bool leaf;//if the current node is a leaf then the value is true
public:
	BTreeNode(int _m,bool _leaf);
	void display();
	BTreeNode *search(int k);
  void insertNonFull(int k);
	void splitChild(int i, BTreeNode *y);
  friend class BTree;
};

class BTree
{
	BTreeNode *root;//Pointer to the root node
	int m;//Minimum degree
public:
	//Constructor to initialize an empty tree
	BTree(int m){root=NULL;this->m=m;}
	//Function to display the tree
	void display(){if(root!=NULL)root->display();}
	BTreeNode* search(int k){return(root==NULL)?NULL:root->search(k);}
  void insert(int k);//main insertion function
};

BTreeNode::BTreeNode(int m,bool leaf)
{
	this->m=m;
	this->leaf=leaf;
	keys=new int[2*m-1];//maximum no of keys in a node is 2*(m-1)
	C=new BTreeNode *[2*m];//maximum no of children in a node is 2*m
	n=0;//Initializing the number of keys=0
}

void BTreeNode::display()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(leaf==false)//means children node is present
			C[i]->display();//recursive call to the child
		cout<<" "<<keys[i];
	}
	//Traversing to the subtree with the last child
	if(leaf==false)
		C[i]->display();//The right node of the last key in root
}

BTreeNode *BTreeNode::search(int k)
{
	//Finding the first key which is greater than or equal to k
	int i=0;
	while(i<n && k>keys[i])i++;
	//If the found key is equal to k,then return this node
	if(keys[i]==k)return this;//element found
	// If the key is not found here and this is a leaf node
	if(leaf==true)return NULL;//element not present
	//else if it's not a leaf node go to it's child
	return C[i]->search(k);
}
///

void BTree::insert(int k)//main inserting function
{
	if(root==NULL)//If tree is empty
	{
		root=new BTreeNode(m,true);//Allocating memory for the new root node
		root->keys[0]=k;//Insert key
		root->n=1;//Update the total number of keys in root
	}
	else//If the tree is not empty
	{
		if(root->n==2*m-1)//If the tree if full
		{
			BTreeNode *s=new BTreeNode(m,false);//Allocate memory for the new root
			s->C[0]=root;//Make the old root as child of the new root
			s->splitChild(0,root);//Split the old root and move 1 key to the new root
			int i=0;
			if(s->keys[0]<k)i++;//Deciding which child gets the new key
			s->C[i]->insertNonFull(k);
			root=s;//setting new root as s
		}
		else //If root is not full
			root->insertNonFull(k);
	}
}

void BTreeNode::insertNonFull(int k)
{
	int i=n-1;//Initializing index as the index of the rightmost element
	if(leaf==true)//If this is a leaf node
	{
	  //to find the location of new key to be inserted
		while(i>=0&&keys[i]>k)//Moves all greater keys to one place ahead
		{
			keys[i+1]=keys[i];
			i--;
		}
		keys[i+1]=k;// Insert the new key at found location
		n++;//Increase the number of keys
	}
	else//If this node is not leaf
	{
		while(i>=0&&keys[i]>k)i--;//Finding the child which is going to have the new key
		if(C[i+1]->n==2*m-1)//If the child will be full
		{
			splitChild(i+1, C[i+1]);//split the child
			if(keys[i+1]<k)i++;//check which child is going to have the key
		}
		C[i+1]->insertNonFull(k);
	}
}

void BTreeNode::splitChild(int i, BTreeNode *y)//y must be full when this function is called
{
	BTreeNode *z=new BTreeNode(y->m,y->leaf);//new node to store (t-1)keys of y
	z->n=m-1;//no of keys this node is going to have
	for(int j=0;j<m-1;j++)//Copying the last (t-1)keys of y to z
    z->keys[j]=y->keys[j+m];
	if(y->leaf==false)//If y isn't a leaf node
	{
		for(int j=0;j<m;j++)//Copying the last t children of y to z,
			z->C[j]=y->C[j+m];
	}
	y->n=m-1;//Reduce the number of keys in y
	for(int j=n;j>=i+1;j--)//creating space for the new child
		C[j+1]=C[j];
	C[i+1]=z;//Linking the new child to this node
	for(int j=n-1;j>=i;j--)//moving all the greater keys one position ahead
		keys[j+1]=keys[j];
	keys[i]=y->keys[m-1];//Copying the middle key of y to this node
	n=n+1;//increase the number of keys present
}

int main()
{
  int choice=0,temp;
  cout<<"Enter the order of the B-Tree: ";cin>>temp;
  BTree t(temp);
  while(1){
    cout<<"\n1.Insert\n2.Search\n3.Display\n4.Exit\nEnter your choice: ";cin>>choice;
    switch(choice){
      case 1:cout<<"Enter the key to insert: ";cin>>temp;t.insert(temp);
      cout<<temp<<" inserted successfully\n";break;
      case 2:cout<<"Enter the key to search: ";cin>>temp;
      (t.search(temp)!=NULL)?cout<<"Element Found\n":cout<<"Element Not Found\n";break;
      case 3:cout<<"The elements of the tree are:\n";t.display();break;
      case 4:exit(0);
      default:cout<<"Invalid Input,Try Again\n";
    }
  }
	return 0;
}

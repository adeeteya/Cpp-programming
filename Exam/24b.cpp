#include<bits/stdc++.h>
using namespace std;

class BTreeNode
{
	int *keys;
	int m;
	BTreeNode **C;
	int n;
	bool leaf;
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
	BTreeNode *root;
	int m;
public:

	BTree(int m){root=NULL;this->m=m;}

	void display(){
    if(root!=NULL){
      cout<<"The elements of the tree are:\n";
      root->display();
    }
    else cout<<"\nThe tree is empty!\n";
  }
	BTreeNode* search(int k){return(root==NULL)?NULL:root->search(k);}
  void insert(int k);
};

BTreeNode::BTreeNode(int m,bool leaf)
{
	this->m=m;
	this->leaf=leaf;
	keys=new int[2*m-1];
	C=new BTreeNode *[2*m];
	n=0;
}

void BTreeNode::display()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(leaf==false)
			C[i]->display();
		cout<<" "<<keys[i];
	}

	if(leaf==false)
		C[i]->display();
}

BTreeNode *BTreeNode::search(int k)
{

	int i=0;
	while(i<n && k>keys[i])i++;

	if(keys[i]==k)return this;

	if(leaf==true)return NULL;

	return C[i]->search(k);
}


void BTree::insert(int k)
{
	if(root==NULL)
	{
		root=new BTreeNode(m,true);
		root->keys[0]=k;
		root->n=1;
	}
	else
	{
		if(root->n==2*m-1)
		{
			BTreeNode *s=new BTreeNode(m,false);
			s->C[0]=root;
			s->splitChild(0,root);
			int i=0;
			if(s->keys[0]<k)i++;
			s->C[i]->insertNonFull(k);
			root=s;
		}
		else
			root->insertNonFull(k);
	}
}

void BTreeNode::insertNonFull(int k)
{
	int i=n-1;
	if(leaf==true)
	{

		while(i>=0&&keys[i]>k)
		{
			keys[i+1]=keys[i];
			i--;
		}
		keys[i+1]=k;
		n++;
	}
	else
	{
		while(i>=0&&keys[i]>k)i--;
		if(C[i+1]->n==2*m-1)
		{
			splitChild(i+1, C[i+1]);
			if(keys[i+1]<k)i++;
		}
		C[i+1]->insertNonFull(k);
	}
}

void BTreeNode::splitChild(int i, BTreeNode *y)
{
	BTreeNode *z=new BTreeNode(y->m,y->leaf);
	z->n=m-1;
	for(int j=0;j<m-1;j++)
    z->keys[j]=y->keys[j+m];
	if(y->leaf==false)
	{
		for(int j=0;j<m;j++)
			z->C[j]=y->C[j+m];
	}
	y->n=m-1;
	for(int j=n;j>=i+1;j--)
		C[j+1]=C[j];
	C[i+1]=z;
	for(int j=n-1;j>=i;j--)
		keys[j+1]=keys[j];
	keys[i]=y->keys[m-1];
	n=n+1;
}

int main()
{
  int choice=0,temp;
  clock_t time_req;
  cout<<"Enter the order of the B-Tree: ";cin>>temp;
  BTree t(temp);
  while(1){
    cout<<"\n1.Insert\n2.Search\n3.Display\n4.Exit\nEnter your choice: ";cin>>choice;
    switch(choice){
      case 1:cout<<"Enter the key to insert: ";cin>>temp;t.insert(temp);
      cout<<temp<<" inserted successfully\n";break;
      case 2:cout<<"Enter the key to search: ";cin>>temp;
      time_req=clock();
      (t.search(temp)!=NULL)?cout<<"Element Found\n":cout<<"Element Not Found\n";
      time_req=clock()-time_req;
      cout<<"Processor time taken for searching: "<<(float)time_req/CLOCKS_PER_SEC<<" seconds\n";
      break;
      case 3:t.display();break;
      case 4:exit(0);
      default:cout<<"Invalid Input,Try Again\n";
    }
  }
	return 0;
}

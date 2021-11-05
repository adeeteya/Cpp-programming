#include<iostream>
using namespace std;
int arr[50][50],n,dummy[50];
int b[20],front=-1,rear=-1;
int c[20],top=-1,count=0;

void bfs(int v){
   int i,current;
   dummy[v]=1;
   b[++rear]=v;
   while(front!=rear){
     current=b[++front];
     for(i=1;i<=n;i++){
       if((arr[current][i]==1)&&(dummy[i]==0)){
        b[++rear]=i;
        dummy[i]=1;
        cout<<i<<" ";
      }
    }
  }
}

void dfs(int v)
{
  int i;
  dummy[v]=1;
  c[++top]=v;
  for(i=1;i<=n;i++){
    if(arr[v][i]==1&&dummy[i]==0){
      cout<<i<<" ";
      dfs(i);
    }
  }
}

int main()
{
   int ch, start, i,j;
   cout << "\nEnter the number of vertices in graph:  ";
   cin >> n;
   cout << "\nEnter the adjacency matrix:\n";
   for(i=1; i<=n; i++)
   {
          for(j=1;j<=n;j++)
                  cin >> arr[i][j];
    }

for(i=1;i<=n;i++)
     dummy[i]=0;
cout << "\nEnter the starting vertex: ";
cin >> start;

  cout << "\n1. BFS";
  cout << "\n2. DFS";
  cout << "\n3:Exit";
  cout << "\nEnter the choice: ";
  cin >> ch;
  switch(ch)
  {
    case 1: cout << "\nNodes reachable are : ";
            bfs(start);
            for(i=1;i<=n;i++)
            {
              if(dummy[i]==0)
              cout << "\nThe vertex not reachable is " << i << "\n";
            }
            break;

    case 2: cout << "\nNodes reachable from starting vertex "<< start << " are: ";
            dfs(start);
            break;
    case 3: exit(0);
    default: cout << "\ninvalid choice\n";
  }
}

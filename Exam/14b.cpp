#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;
int arr[50][50],n,visited[50];

void dfs(int v) {
  int i;
  visited[v]=1;//marking v as visited
  for(i=1;i<=n;i++){
    if(arr[v][i]==1&&visited[i]==0){//not visited
      cout<<i<<" ";
      dfs(i);
    }
  }
}

int main() {
  int i,j,start;
  cout<<"Enter the number of vertices in graph: ";
  cin>>n;
  cout<<"Enter the adjacency matrix:\n";
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      cin>>arr[i][j];
  for(i=1;i<=n;i++)
    visited[i]=0;
  cout<<"\nEnter the starting vertex: ";
  cin>>start;
  cout<<"\nNodes reachable from starting vertex "<<start<<" are: ";
  auto starttime=high_resolution_clock::now();
  dfs(start);
  auto endtime=high_resolution_clock::now();
  auto duration=duration_cast<microseconds>(endtime-starttime);
  cout<<"Time taken is "<<duration.count()<<"ms"<<endl;
}

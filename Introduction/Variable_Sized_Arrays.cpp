#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q,k,i,j;
    cin>>n>>q;
    int *a[n];
    for(int it=0;it<n;it++){
        cin>>k;
        a[it]=new int[k];
        for(int jt=0;jt<k;jt++)
            cin>>a[it][jt];
    }
    for(int it=0;it<q;it++){
        cin>>i>>j;
        cout<<a[i][j]<<endl;
    }
    return 0;
}
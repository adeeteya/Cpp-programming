#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,temp,i,j;
    cin>>N;
    vector<int> v;
    for(int i=0;i<N;i++){
        cin>>temp;
        v.push_back(temp);
    }
    cin>>i;
    v.erase(v.begin()+i-1);
    cin>>i>>j;
    v.erase(v.begin()+i-1,v.begin()+j-1);
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v.at(i);
        cout<<" ";
    }
    return 0;
}

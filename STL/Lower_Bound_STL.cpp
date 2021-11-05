#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,Q,temp;vector<int>::iterator it;
    cin>>N;
    vector<int> X;
    for(int i=0;i<N;i++){
        cin>>temp;
        X.push_back(temp);
    }
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>temp;
        it=lower_bound(X.begin(),X.end(),temp);
        if(temp==X.at(it-X.begin())){
            cout<<"Yes "<<it-X.begin()+1<<endl;
        }
        else{
            cout<<"No "<<it-X.begin()+1<<endl;
        }
    }
    return 0;
}

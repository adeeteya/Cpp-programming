#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int Q,x,y;
    set<int>s;set<int>::iterator f;
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>y>>x;
        if(y==1){
            s.insert(x);
        }
        else if(y==2){
            s.erase(x);
        }
        else{
            f=s.find(x);
            if(f!=s.end())cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}

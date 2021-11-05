#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int Q,Y,type;string X;
    map<string,int> m;
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>type>>X;
        if(type==1){
            cin>>Y;
            m[X]+=Y;
        }
        else if(type==2){
            m.erase(X);
        }
        else{
            cout<<m[X]<<endl;
        }
    }
    return 0;
}

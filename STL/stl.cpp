#include<iostream>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int main(){
    cout<<"\nStack:\n";
    stack<int> a;
    a.push(9);a.push(2);a.push(5);a.push(7);a.push(3);
    while(!a.empty()){
        cout<<a.top()<<" ";a.pop();
    }
    cout<<"\nQueue:\n";
    queue<int> b;
    b.push(9);b.push(2);b.push(5);b.push(7);b.push(3);
    while(!b.empty()){
        cout<<b.front()<<" ";b.pop();
    }
    cout<<"\nList:\n";
    list<int> c;
    c.push_back(5);c.push_front(4);c.push_back(6);
   list<int>::iterator it;
   for(it=c.begin();it!=c.end();it++){
       cout<<*it<<" ";
   }
    return 0;
}
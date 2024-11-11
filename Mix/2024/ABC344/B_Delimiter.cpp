#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<int> s;
    int x;
    while(cin>>x){
        s.push(x);
        if(x==0) break;
    }
    while(s.size()) cout<<s.top()<<'\n',s.pop();
}
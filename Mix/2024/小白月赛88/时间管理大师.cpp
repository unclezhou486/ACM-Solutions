#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

bool v[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int h,m;
        cin>>h>>m;
        int res=h*60+m;
        v[res-1]=v[res-3]=v[res-5]=1;
    }
    queue<int> q;
    for(int i=1;i<=100000;i++){
        if(v[i]) q.push(i);
    }
    cout<<q.size()<<'\n';
    while(q.size()){
        int x=q.front();
        cout<<x/60<<' '<<x%60<<'\n';
        q.pop();
    }
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e4+10;

int n,m;

int a[N],b[N],c[N];
priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,greater<pair<pair<int,int>,int> > >q;
int jisuan(int x,int i){
    return a[i]*x*x+b[i]*x+c[i];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        q.push({{jisuan(1,i),i},1});
    }
    while(m--){
        cout<<q.top().first.first<<' ';
        q.push({{jisuan(q.top().second+1,q.top().first.second),q.top().first.second},q.top().second+1});
        q.pop();
    }
}
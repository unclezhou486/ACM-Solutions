#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;

int a[N];

void solve(){
    map<int,vector<int> > ma;
    ma.clear();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma[a[i]].push_back(i);
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        if(x==y) continue;
        if(ma[y].size()<ma[x].size()){
            swap(ma[x],ma[y]);
        }
        for(auto v:ma[x]){
            ma[y].push_back(v);
        }
        ma[x].clear();
    }
    for(auto [x,y]:ma){
        for(auto v:y){
            a[v]=x;
        }
        ma[x].clear();
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> c(n);
    vector<vector<int> > ne(n);
    for(int i=0;i<n;i++) cin>>c[i],c[i]--;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        ne[u].push_back(v);
        ne[v].push_back(u);
    }
    long long ans=0;
    vector<map<int,int> > ma(n);
    auto dfs =[&](auto self,int x,int p) -> void {
        for(auto y:ne[x]){
            if(y==p) continue;
            self(self,y,x);
            if(ma[y].count(c[x])){
                ans+=ma[y][c[x]];
                ma[y].erase(c[x]);
            }
            if(ma[x].size()<ma[y].size()){
                swap(ma[x],ma[y]);
            }
            for(auto [a,b]:ma[y]){
                ans+=1ll*b*ma[x][a];
                ma[x][a]+=b;
            }
            ma[y].clear();
        }
        ma[x][c[x]]++;
    };
    dfs(dfs,0,-1);
    cout<<ans<<'\n';
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
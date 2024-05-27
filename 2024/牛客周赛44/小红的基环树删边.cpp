#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<pair<int,int> > > adj(n+1);
    vector<int> dp(n+1),vis(n+1);
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        dp[i]=1e9;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    auto dfs = [&] (auto self,int x,int dep) -> void {
        if(x==n){
            for(int i=1;i<=n;i++){
                if(!vis[i]){
                    dp[i]=min(dp[i],dep);
                }
            }
            return;
        }
        for(auto [u,v]:adj[x]){
            if(!vis[v]){
                vis[v]=1;
                self(self,u,dep+1);
                vis[v]=0;
            }
        }
    };
    dfs(dfs,1,0);
    for(int i=1;i<=n;i++){
        cout<<((dp[i]==1e9)?-1:dp[i])<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
//https://codeforces.com/problemset/problem/1375/G
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int> > adj(n+5);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int w=0,b=0;
    auto dfs = [&] (auto self,int x,int fa,int col) -> void {
        if(col) w++;
        else b++;
        for(auto v:adj[x]){
            if(v==fa) continue;
            self(self,v,x,col^1);
        }
    };
    dfs(dfs,1,1,1);
    cout<<min(w,b)-1<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
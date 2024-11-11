#include <bits/stdc++.h>


void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int> > ne(n);
    std::vector<int> son(n);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        u--,v--;
        ne[u].push_back(v);
        ne[v].push_back(u);
    }
    int ans=0;
    auto dfs = [&](auto self,int x,int fa) -> void {
        son[x]=1;
        for(auto v:ne[x]){
            if(v==fa) continue;
            self(self,v,x);
            son[x]+=son[v];
        }
        if(son[x]%2==0&&x) ans++;
    };
    dfs(dfs,0,0);
    if(n&1) std::cout<<"-1\n";
    else std::cout<<ans<<'\n';
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    solve();
    return 0;
}
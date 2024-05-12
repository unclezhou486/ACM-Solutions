#include <bits/stdc++.h>


void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int> > ne(n);
    std::map<std::pair<int,int>,int> ma;
    std::vector<int> son(n);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        u--,v--;
        ne[u].push_back(v);
        ne[v].push_back(u);
    }
    auto dfs = [&](auto self,int x,int fa) -> void {
        son[x]=1;
        for(auto v:ne[x]){
            if(v==fa) continue;
            self(self,v,x);
            son[x]+=son[v];
        }
        if(son[x]%2==0){
            ma[{x,fa}]=1;
            ma[{fa,x}]=1;
        }
    };
    dfs(dfs,0,0);
    std::vector<int> f(n);
    for(int i=0;i<n;i++) f[i]=i;
    auto find=[&](auto find,int x) -> int {
        return f[x]==x?f[x]:f[x]=find(find,f[x]);
    };
    for(int i=0;i<n;i++){
        for(auto v:ne[i]){
            if(!ma.count({i,v})){
                f[find(find,v)]=find(find,i);
            }
        }
    }
    std::map<int,int> maa;
    for(int i=0;i<n;i++){
        maa[find(find,i)]++;
    }
    int ans=0;
    bool fl=0;
    for(auto [a,b]:maa){
        if(b%2){
            fl=1;
            break;
        }
        ans++;
    }
    if(fl) std::cout<<"-1\n";
    else std::cout<<ans-1<<'\n';
    //if(ans||n%2==0) std::cout<<ans<<'\n';
    //else std::cout<<-1<<'\n';
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    solve();
    return 0;
}
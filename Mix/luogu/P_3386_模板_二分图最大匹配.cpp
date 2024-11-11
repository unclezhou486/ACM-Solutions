#include <bits/stdc++.h>

using namespace std;

struct KMA {
    vector<vector<int> > adj;
    vector<int> mch,vistime;
    int n,m;
    int res;
    KMA() {}
    KMA(int n,int m){
        init(n,m);
    }
    void init(int n,int m){
        this->n=n;
        this->m=m;
        res=0;
        adj.assign(n+1,{});
        mch.resize(m+1);
        vistime.resize(n+1);
        mch.assign(m+1,0);
        vistime.assign(n+1,0);
       
    }
    void add(int from,int to){
        adj[from].push_back(to);
    }
    bool dfs(int u,int tag){
        if(vistime[u]==tag) return false;
        vistime[u]=tag;
        for(auto v:adj[u]){
            if((mch[v]==0)||dfs(mch[v],tag)){
                mch[v]=u;
                return true;
            }
        }
        return false;
    }
    void solve(){
        for(int i=1;i<=n;i++){
            if(dfs(i,i)){
                res++;
            }
        }
    }
};

void solve(){
    int n,m,e;
    cin>>n>>m>>e;
    KMA KM(n,m);
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        KM.add(u,v);
    }
    KM.solve();
    cout<<KM.res<<'\n';
}


int main(){
    solve();
    return 0;
}
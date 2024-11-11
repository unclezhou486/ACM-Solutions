//https://codeforces.com/problemset/problem/1592/F2
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
    int n,m;
    cin>>n>>m;
    KMA KM(n,m);
    vector<vector<int> > a(n+5,vector<int>(m+5));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch;
            cin>>ch;
            if(ch=='B') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]^=a[i+1][j]^a[i][j+1]^a[i+1][j+1];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]&&a[i][m]&&a[n][j]){
                KM.add(i,j);
            }
        }
    }
    KM.solve();
    int res=KM.res;
    a[n][m]^=(res&1);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans+=a[i][j];
        }
    }
    ans-=res;
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n,m;
int a[N];
//int op[N];
//int e[N],ne[N],h[N],idx;
int pre[N],op[N],loc[N],val[N];
int ans[N];
vector<int> g[N];

void add_edge(int u,int v){
    g[u].push_back(v);
}

void dfs(int u){
    if(op[u]==2){
        ans[u]=a[loc[u]];
        for(auto v:g[u]){
            dfs(v);
        }
    }
    else{
        int res=a[loc[u]];
        a[loc[u]]=val[u];
        for(auto v:g[u]){
            dfs(v);
        }
        a[loc[u]]=res;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        cin>>pre[i]>>op[i]>>loc[i];
        if(op[i]==1)cin>>val[i];
        add_edge(pre[i],i);
    }
    dfs(0);
    for(int i=1;i<=m;i++){
        if(op[i]==2){
            cout<<ans[i]<<'\n';
        }
    }
}
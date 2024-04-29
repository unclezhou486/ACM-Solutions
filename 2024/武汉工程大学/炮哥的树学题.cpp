#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;

int n,k;

int a[N];
int dep[N];
int sum[N];
int pos[N];
vector<int> ne[N];

void dfs1(int x,int fa){
    sum[x]=a[x];
    dep[x]=dep[fa]+1;
    for(auto v:ne[x]){
        if(v==fa) continue;
        dfs1(v,x);
        sum[x]+=sum[v];
    }
}

void dfs2(int x,int fa){
    if(dep[x]-k-1>0)sum[pos[dep[x]-k-1]]-=sum[x];
    pos[dep[x]]=x;
    for(auto v:ne[x]){
        if(v==fa) continue;
        dfs2(v,x);
        //sum[son[dep[x]]]=;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    //vector<>
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        ne[u].push_back(v);
        ne[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        cout<<sum[i]<<' ';
    }
    return 0;
}
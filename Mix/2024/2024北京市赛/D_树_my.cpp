#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;
int n,m,q;
int e[N<<1],ne[N<<1],h[N],idx;

int f[N][30];
int dep[N];

void add(int x,int y){
    e[++idx]=y;
    ne[idx]=h[x];
    h[x]=idx;
}

void dfs(int x,int fa){
    f[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(int i=1;i<30;i++){
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x);
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=29;i>=0;i--){
        if(dep[f[x][i]]>=dep[y]){
            x=f[x][i];
        }
    }
    if(x==y) return x;
    for(int i=29;i>=0;i--){
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}

int b[N];
int ans[N];
int anss;

int len(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}

void check(int x){
    if(x==1||x==m) return;
    anss-=ans[x];
    ans[x]=0;
    if(len(b[x-1],b[x+1])!=len(b[x-1],b[x])+len(b[x],b[x+1])) ans[x]=1,anss++;
    return;
}

void solve(){

    cin>>n>>m>>q;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,1);
    ans[1]=ans[m]=1;
    if(m==1) anss=1;
    else anss=2;
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    for(int i=1;i<=m;i++){
        check(i);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        b[x]=y;
        for(int i=max(1,x-1);i<=min(m,x+1);i++){
            check(i);
        }
        cout<<anss<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
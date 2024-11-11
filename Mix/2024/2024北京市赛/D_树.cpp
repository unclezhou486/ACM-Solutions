#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<unordered_map>
#define ll long long
#define int long long
using namespace std;
const int N=2e5+5;
const int MOD=998244353;
const int INF=1e18;
const int C=500;
vector<int>a[N];
queue<int>q;
struct Edge{
    int v,w,next;
}edge[2*N];
int tot,head[N],f[N][100],d[N];
void AddEdge(int u,int v,int w){
    edge[++tot].v=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot;
}
void dfs(int x){
   for(int i=head[x];i;i=edge[i].next){
    int v=edge[i].v;
    if(d[v])continue;
    d[v]=d[x]+1;
    f[v][0]=x;
    for(int i=1;f[f[v][i-1]][i-1];i++)f[v][i]=f[f[v][i-1]][i-1];
    dfs(v);
   } 
}
int lca(int u,int v){
    if(d[u]<d[v])swap(u,v);
    while(d[u]!=d[v])u=f[u][(int)log2(d[u]-d[v])];
    if(u==v)return u;
    else {
        int t=(int)log2(d[u]);
        while(f[u][0]!=f[v][0]){
            while(f[u][t]==f[v][t])t--;
            u=f[u][t],v=f[v][t];
        }
        return f[u][0];
    }
}
int n,m,qq;
int ans[N],sum;
int p[N];
void cheak(int x){
    if(x==1||x==m)return;
    sum-=ans[x];
    ans[x]=0;
    int _=lca(p[x-1],p[x+1]);
    int dm=d[p[x-1]]+d[p[x+1]]-2*d[_];
    int _1=lca(p[x-1],p[x]),_2=lca(p[x],p[x+1]);
    int dm1=d[p[x-1]]+d[p[x]]-2*d[_1],dm2=d[p[x]]+d[p[x+1]]-2*d[_2];
    if(dm!=dm1+dm2)ans[x]=1,sum+=1;
}
void solve(){
    cin>>n>>m>>qq;
    if(m==1) sum=1;
    else sum=2;
    ans[1]=ans[m]=1;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        AddEdge(u,v,1);
        AddEdge(v,u,1);
    }
    d[1]=1;
    dfs(1);
    for(int i=1;i<=m;i++)cin>>p[i];
    for(int i=1;i<=m;i++)cheak(i);
    for(int i=1;i<=qq;i++){
        int _,__;
        cin>>_>>__;
        p[_]=__;
        for(int u=max(1ll,_-1);u<=min(m,_+1);u++)cheak(u);
        // for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
        cout<<sum<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)solve();
}

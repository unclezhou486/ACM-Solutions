#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n;
int r,t0;

int e[N<<1],ne[N<<1],h[N],idx;

int dep[N];
int f[N][20];

bool v[N],vis[N];
int stk[N],top;

int len;
int tlen[N];
int ans[N];

void add(int x,int y){
    e[++idx]=y,ne[idx]=h[x],h[x]=idx;
}

int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=19;i>=0;i--){
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i],y=f[y][i];
        }
    }
    return f[x][0];
}

void bfs(){
    queue<int> q;
    q.push(r);
    dep[r]=1;vis[r]=1;
    v[stk[++top]=r]=1;
    while(q.size()){
        int y=q.front();
        q.pop();
        for(int i=h[y];i;i=ne[i]){
            int x=e[i];
            if(vis[x]) continue;
            vis[x]=1;
            q.push(x);
            f[x][0]=y;
            dep[x]=dep[f[x][0]]+1;
            for(int i=1;i<=19;i++){
                f[x][i]=f[f[x][i-1]][i-1];
            }
            if(v[f[x][0]]){
                len++;
                v[x]=1;
                for(;top;top--) v[stk[top]]=0;
                stk[++top]=x;
            }
            else{
                int lc=lca(stk[1],x);
                len=max(len,dep[x]+dep[stk[1]]-dep[lc]*2);
                if(dep[x]==dep[stk[1]]) v[stk[++top]=x]=1;
            }
            tlen[dep[x]-1]=max(tlen[dep[x]-1],len);
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    cin>>r>>t0;
    bfs();
    int t=t0;
    for(int i=1;i<=n;i++){
        tlen[i]=max(tlen[i],min(tlen[i-1]+1,len));
    }
    for(int k=n;k>=1;k--){
        while(tlen[min(t,n)]>k*(t-t0)*2){
            t++;
        }
        ans[k]=t;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    return 0;
}
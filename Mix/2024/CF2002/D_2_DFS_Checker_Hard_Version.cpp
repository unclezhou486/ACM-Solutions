#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

const int N=3e5+10;

int n,q;
int fa[N];
int p[N];
vector<int> adj[N];
bool fine[N];
int cnt;
int f[N][21];
int dep[N];

void init(){
    for(int i=1;i<=n;i++) adj[i].clear(),fine[i]=0;
    cnt=0;
}

void dfs(int x,int fa){
    f[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(int i=1;i<=20;i++){
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for(auto y:adj[x]){
        if(y==fa) continue;
        dfs(y,x);
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y]){
        swap(x,y);
    }
    for(int i=20;i>=0;i--){
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    }
    if(x==y) return x;
    for(int i=20;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i],y=f[y][i];
        }
    }
    return f[x][0];
}
set<int> se;
set<int> see;
void check(int x){
    if(x>n) return;
    if(x==1){
        cnt-=fine[x];
        if(p[x]==1) fine[x]=1;
        else fine[x]=0;
        cnt+=fine[x];
    }
    else{
        cnt-=fine[x];
        if(lca(p[x],p[x-1])==fa[p[x]]) fine[x]=1;
        else fine[x]=0;
        cnt+=fine[x];
    }
}

void solve(){
    cin>>n>>q;
    init();
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        adj[fa[i]].push_back(i);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++){
        check(i);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        swap(p[x],p[y]);
        check(x),check(y);
        check(x+1),check(y+1);
        // for(auto u:se){
        //     check(u);
        // }
        // for(auto u:see){
        //     se.erase(u);
        // }
        // see.clear();
        if(cnt==n){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
6 3

1 1 3 3 1

2 3 6 4 5 1

3 5

1 2

6 1
*/

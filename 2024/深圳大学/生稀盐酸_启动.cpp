#pragma GCC O(2)
#pragma GCC O(3)
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int e[N<<1],ne[N<<1],h[N],idx;
int f[N];
int a[N],b[N];

void add(int x,int y){
    e[++idx]=y,ne[idx]=h[x],h[x]=idx;
}

void dfs(int x,int fa){
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        f[j]=x;
        dfs(j,x);
    }
}

void solve(){
    int n;
    int ans=0;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,1);
    queue<pair<int,int> > q;
    vector<int > vec;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=0;
        if(a[i]<0) q.push({i,0});
    }
    int res=0;
    while(q.size()){
        pair<int,int> pos=q.front();
        q.pop();
        int x=pos.first;
        int dep=pos.second;
        if(dep!=res){
            for(auto ver:vec){
                if(abs(b[ver])>a[ver]){
                    b[ver]+=a[ver];
                    a[ver]=b[ver];
                }
                b[ver]=0;
            }
            vec.clear();
            res=dep;
        }
        if(x==1) {ans=max(ans,-a[1]),a[1]=0;continue;}
        if(a[x]<0){
            if(b[f[x]]) {b[f[x]]+=a[x];a[x]=0;continue;}
            else b[f[x]]=a[x],vec.push_back(f[x]),q.push({f[x],dep+1});a[x]=0;
        }
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        h[i]=0;
    }
    idx=0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
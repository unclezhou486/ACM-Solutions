#pragma GCC O(2)
#pragma GCC O(3)
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int e[N<<1],ne[N<<1],h[N],idx;
int f[N];
int a[N],b[N];

map<pair<int,int>,int> ma;
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
    ma.clear();
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,1);
    queue<pair<int,int> > q;
    vector<pair<int,int> > vec;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=0;
        if(a[i]<0) q.push({i,0}),b[i]=a[i];
    }
    int res=0;
    while(q.size()){
        pair<int,int> pos=q.front();
        q.pop();
        int x=pos.first;
        int dep=pos.second;
        if(dep!=res){
            set<int> se;
            for(auto [ver,val]:vec){
                b[ver]+=val;
                se.insert(ver);
            }
            for(auto ver:se){
                if(abs(b[ver])>a[ver]){
                    b[ver]+=a[ver];
                    a[ver]=0;
                }
                else{
                    b[ver]=0;
                }
            }
            vec.clear();
            res=dep;
        }
        if(x==1) continue;
        if(ma[{x,dep}]) continue;
        ma[{x,dep}]=1;
        //cout<<x<<' '<<b[x]<<' '<<dep<<'\n';
        if(b[x]<0)vec.push_back({f[x],b[x]});
        q.push({f[x],dep+1});b[x]=0;
    }
    cout<<-b[1]<<'\n';
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
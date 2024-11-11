#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+10;
const int INF=1e18;

struct node{
    int v,w;
};    
int n,m,k;
int d[N];
bool vis[N];
vector<node> ve[N];
void dij(int x){
    for(int i=1;i<=n;i++){
        int ver=0,minn=INF;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&d[j]<minn){
                ver=j,minn=d[j];
            }
        }
        if(minn==INF) return;
        vis[ver]=1;
        for(auto it:ve[ver]){
            int w=it.w;
            int v=it.v;
            d[v]=min(d[v],d[ver]+w);
        }
    }
}

void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++){
        d[i]=INF;
        vis[i]=0;
        ve[i].clear();
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        for(int i=0;i<n;i++){
            ve[i].push_back({(i+x)%n,y});
        }
    }
    d[k%n]=0;
    dij(k);
    //for(int i=1;i<=n;i++) cout<<d[i]<<'\n';
    if(d[0]==INF) cout<<-1<<'\n';
    else cout<<d[0]<<'\n';
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
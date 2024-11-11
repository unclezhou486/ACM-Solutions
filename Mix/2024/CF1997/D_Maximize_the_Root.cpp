#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<vector<int> > adj(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    auto dfs= [&] (auto self,int x) -> int {
        int minn=1e9;
        for(auto y:adj[x]){
            minn=min(minn,self(self,y));
        }
        if(adj[x].size()==0){
            return a[x];
        }
        if(x==1){
            return a[x]+minn;
        }
        if(a[x]<minn){
            minn=(a[x]+minn)/2;
        }
        //cout<<x<<' '<<a[x]<<' '<<minn<<'\n';
        return minn;
    };
    int ans=dfs(dfs,1);
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
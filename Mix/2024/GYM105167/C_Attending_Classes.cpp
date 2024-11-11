#include <bits/stdc++.h>

using namespace std;

const int mod=998244353;

void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<int> > ne(n),parent(n,vector<int>(20));
    vector<int> dep(n),du(n);
    vector<long long >dp(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        ne[u].push_back(v);
        ne[v].push_back(u);
        du[u]++,du[v]++;
    }
    for(int i=0;i<n;i++) dp[i]=du[i]-1;
    auto dfs = [&] (auto self,int x,int fa) -> void {
        dep[x]=dep[fa]+1;
        parent[x][0]=fa;
        for(int i=1;i<20;i++){
            parent[x][i]=parent[parent[x][i-1]][i-1];
        }
        for(auto y:ne[x]){
            if(y==fa) continue;
            if(dp[x])dp[y]*=dp[x];
            dp[y]%=mod;
            self(self,y,x);
            //dp[x]*=dp[y];
            //dp[x]%=mod;
        }
    };
    //for(int i=0;i<n;i++) cout<<dp[i]<<'\n';
    dfs(dfs,0,0);
    auto lca = [&] (int x,int y) -> int {
        if(x==y) return x;
        if(dep[x]<dep[y]) swap(x,y);
        for(int i=19;~i;i--){
            if(dep[parent[x][i]]>=dep[y]) x=parent[x][i];
        }
        if(x==y) return x;
        for(int i=19;~i;i--){
            if(parent[x][i]!=parent[y][i]){
                x=parent[x][i],y=parent[y][i];
            }
        }
        return parent[x][0];
    };
    auto qmi = [&] (long long a,long long b) -> long long {
        long long res=1;
        while(b){
            if(b&1) res=res*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return res;
    };
    auto inv = [&] (long long x) -> long long {
        return qmi(x,mod-2);
    };
    for(int i=0;i<n;i++){
        if(!dp[i]) dp[i]=1;
        //cout<<dp[i]<<' ';
    }
    //cout<<'\n';
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        int l=lca(x,y);
        long long ans;
        //cout<<x<<' '<<y<<' '<<l<<'\n';
        if(l==x){
            ans=dp[parent[y][0]]*inv(dp[x]);
            ans%=mod;
            ans*=du[x];
            ans%=mod;
        }
        else if(l==y){
            //cout<<x<<' '<<y<<' '<<l<<'\n';
            ans=dp[parent[x][0]]*inv(dp[y]);
            ans%=mod;
            //cout<<ans<<' ';
            ans*=du[x];
            //cout<<ans<<' ';
            ans%=mod;
        }
        else{
            ans=du[x];
            x=parent[x][0],y=parent[y][0];
            //cout<<x<<' '<<y<<' '<<dp[x]<<' '<<dp[y]<<'\n';
            ans*=dp[x],ans%=mod;
            ans*=dp[y],ans%=mod;
            long long res=inv(dp[l]);
            ans*=res,ans%=mod;
            ans*=res,ans%=mod;
            ans*=(du[l]-1);
            ans%=mod;
        }
        //cout<<ans<<'\n';
        //long long ans=dp[]*dp[y];
        ////cout<<l<<' '<<dp[l]<<' '
        //long long res=inv(dp[l]);
        //cout<<l<<' '<<dp[l]<<' '<<res<<' '<<dp[x]<<' '<<dp[y]<<'\n';
        //ans%=mod;
        //ans*=res;ans%=mod;
        //ans*=res;ans%=mod;
        cout<<ans<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
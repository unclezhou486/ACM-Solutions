#include <bits/stdc++.h>

using namespace std;

const int INF=1e9;

void solve(){
    int n,m,maxn;
    cin>>n>>m;
    vector<int> a(n+1),b(n+1);
    vector<long long> c(m+1);
    for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    vector<int> best(maxn+1),ans(maxn+1);
    for(int i=0;i<=maxn;i++) best[i]=INF;
    for(int i=1;i<=n;i++){
        best[a[i]]=min(best[a[i]],a[i]-b[i]);
    }
    for(int i=1;i<=maxn;i++){
        best[i]=min(best[i],best[i-1]);
        if(i-best[i]<0) continue;
        ans[i]=2+ans[i-best[i]];
    }
    long long anss=0;
    for(int i=1;i<=m;i++){
        long long x=c[i];
        long long k=(x-maxn+best[maxn])/best[maxn];
        if(k<0) k=0;
        long long res=0;
        res=2*k+ans[x-k*best[maxn]];
        anss+=res;
    }
    cout<<anss<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
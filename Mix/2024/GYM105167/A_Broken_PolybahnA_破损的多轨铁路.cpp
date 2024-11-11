#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

const int mod=1e9+7;

int ru[N];

//int jie[N];

long long qmi(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    //jie[0]=1;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        ru[u]++,ru[v]++;
        
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        long long res=0;
        res=qmi(2,ru[i]);
        res-=1;
        ans+=res;
        ans%=mod;
        //cout<<res<<' '<<ans<<'\n';
    }
    ans+=mod;
    ans%=mod;
    ans-=(n-1);
    ans%=mod;
    ans+=mod;
    ans%=mod;
    cout<<ans<<'\n';
}

signed main(){
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
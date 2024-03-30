#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod=998244353;

int t;

void solve(){
    int n;
    int res=0;
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ans=ans+((res+x*i)%mod);
        //cout<<ans<<' '<<res*x<<'\n';
        ans%=mod;
        res=res+i*x;
        res%=mod;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
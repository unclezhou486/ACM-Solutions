#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;

int a[N],b[N];

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int res=0;
    int ans=-1;
    for(int i=n;i>=1;i--){
        if(i<=m){
            if(ans==-1) ans=a[i]+res;
            else{
                ans=min(ans,a[i]+res);
            }    
        }
        res+=min(a[i],b[i]);
    }
    cout<<ans<<'\n';
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
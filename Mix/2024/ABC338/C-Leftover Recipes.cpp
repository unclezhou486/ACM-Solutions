#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> q(n+1);
    vector<int> a(n+1);
    vector<int> b(n+1);
    int maxnn;
    for(int i=1;i<=n;i++) cin>>q[i];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]){
            maxnn=max(maxnn,q[i]/a[i]);
        }
    }
    for(int i=1;i<=n;i++) cin>>b[i];
    int ans=0;
    for(int aa=0;aa<=maxnn;aa++){
        int res=1e9;
        for(int j=1;j<=n;j++){
            if(q[j]-a[j]*aa<0) break;
            if(b[j]!=0)res=min((q[j]-a[j]*aa)/b[j],res);
            if(j==n) ans=max(ans,aa+res);
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
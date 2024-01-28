#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int res=0;
    if(k==1){
        cout<<n<<'\n';
        return;
    }
    for(int i=1;i<=sqrt(n)+1;i++){
        if((n%i)==0){
            if(n/i>=k)res=max(i,res);
            if(i>=k) res=max(n/i,res);
        }
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    //cin>>t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(char j='a';j<='a'+k-1;j++){
            cout<<j;
        }
    }
    cout<<'\n';
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
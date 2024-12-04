#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int res=min(n,k)*min(m,k);
    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
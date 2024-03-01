#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    if(n>m) swap(n,m);
    if(n==1) cout<<1<<'\n';
    else if(n==2){
        cout<<(m+1)/2<<'\n';
    }
    else if(n==3&&m==3){
         cout<<8<<'\n';
    }
    else cout<<n*m<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
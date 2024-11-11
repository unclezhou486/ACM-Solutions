#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n,m;
    cin>>n>>m;
    long long x=max(0ll,n-m);
    long long ans=0;
    m=m+(min(n,m));
    long long res=0;
    for(int i=0;i<=32;i++){
        int d=((x>>i)&1);
        if(!d){
            if((1ll<<i)-res<=m){
                ans|=(1ll<<i);
            }
        }
        else{
            res|=(1ll<<i);
            ans|=(1ll<<i);
        }
    }
    cout<<ans<<'\n';
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
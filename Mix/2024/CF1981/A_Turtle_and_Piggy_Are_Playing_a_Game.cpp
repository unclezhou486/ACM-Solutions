#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l,r;
    cin>>l>>r;
    long long x=1;
    long long res=0;
    long long ans=0;
    while(x<=r){
        if(x>=l)ans=max(ans,res);
        x*=2;
        res++;
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
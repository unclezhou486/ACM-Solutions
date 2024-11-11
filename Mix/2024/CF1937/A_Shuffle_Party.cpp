#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    int x=1;
    while(2*x<=n){
        x*=2;
    }
    cout<<x<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
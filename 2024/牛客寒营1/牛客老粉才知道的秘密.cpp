#include <bits/stdc++.h>

using namespace std;

int t,n;

void solve(){
    cin>>n;
    if(n<=6){
        cout<<1<<'\n';
        return;
    }
    if(n%6){
        cout<<n/6*2<<'\n';
    }
    else{
        cout<<n/6<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
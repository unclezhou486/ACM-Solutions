#include <bits/stdc++.h>

using namespace std;

const int N=1e2;

int n,s[N];

void solve(){
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ans+=abs(x);
    }
    cout<<ans<<'\n';
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

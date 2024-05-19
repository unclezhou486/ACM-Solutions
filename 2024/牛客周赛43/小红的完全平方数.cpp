#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int x;
    cin>>x;
    set<int> se;    
    for(int i=1;i<=1000000;i++){
        se.insert(i*i);
    }
    int ans=1e18;
    for(auto y:se){
        if(abs(y-x)%2==0){
            ans=min(ans,abs(y-x)/2);
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
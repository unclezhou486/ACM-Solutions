#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x,y;
    cin>>x>>y;
    int res=max(x,y)-min(x,y);
    if(res%3){
        cout<<"No\n";
    }
    else cout<<"Yes\n";
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
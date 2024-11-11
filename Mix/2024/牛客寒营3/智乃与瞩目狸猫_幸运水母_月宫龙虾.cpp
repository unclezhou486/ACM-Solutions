#include <bits/stdc++.h>

using namespace std;

void solve(){
    string a,b;
    cin>>a>>b;
    if(a[0]>=97) a[0]-=('a'-'A');
    if(b[0]>=97) b[0]-=('a'-'A');
    if(a[0]==b[0]) cout<<"Yes\n";
    else cout<<"No\n";
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
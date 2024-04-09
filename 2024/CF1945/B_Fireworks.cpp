#include <bits/stdc++.h>

using namespace std;

long long a,b,c;

void solve(){
    cin>>a>>b>>c;
    cout<<(c/a+c/b+2)<<'\n';
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
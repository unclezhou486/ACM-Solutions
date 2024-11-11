#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cout<<i<<' '<<j<<' '<<j<<' '<<0<<' '<<i<<' '<<j<<' '<<1<<' '<<i<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<":\n";
        solve();
    }
    return 0;
}
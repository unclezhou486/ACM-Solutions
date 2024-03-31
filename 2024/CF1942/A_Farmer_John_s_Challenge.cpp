#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    if(n==m){
        for(int i=1;i<=n;i++){
            cout<<1<<' ';
        }
        cout<<'\n';
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            cout<<i<<' ';
        }
        cout<<'\n';
    }
    else cout<<-1<<'\n';
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
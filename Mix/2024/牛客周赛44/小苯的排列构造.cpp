#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n<8){
        cout<<-1<<'\n';
        return;
    }
    for(int i=5;i<=n;i++){
        cout<<i<<' ';
    }
    cout<<(n%2?"2 1 4 3":"1 2 3 4");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
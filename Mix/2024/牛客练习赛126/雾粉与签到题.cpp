#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    int minn=a[2];
    for(int i=2;i<n;i++) minn=min(minn,a[i]);
    cout<<minn<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
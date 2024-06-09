#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(7);
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        int res=ch-'A';
        a[res]++;
    }
    int ans=0;
    for(int i=0;i<7;i++){
        if(a[i]<m) ans+=m-a[i];
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
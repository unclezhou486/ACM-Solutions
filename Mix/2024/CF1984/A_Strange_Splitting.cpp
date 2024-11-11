#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    if(a[1]==a[n]){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        if(a[n-1]-a[2]!=a[n]-a[1]){
            cout<<"R";
            for(int i=1;i<n-1;i++) cout<<"B";
            cout<<"R";
            cout<<'\n';
        }
        else{
            cout<<"R";
            for(int i=1;i<n;i++) cout<<"B";
            cout<<'\n';
        }
    }
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
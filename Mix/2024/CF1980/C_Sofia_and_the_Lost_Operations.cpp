#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    map<int,int> vis;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i],vis[b[i]]=1;
    int m;
    map<int,int> ma;
    cin>>m;
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        ma[x]++;
        if(i==m){
            if(!vis[x]){
                cout<<"NO\n";
                return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            if(ma[b[i]]){
                ma[b[i]]--;
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
    return;
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
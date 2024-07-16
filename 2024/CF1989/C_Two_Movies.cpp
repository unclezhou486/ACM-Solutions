#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int dis=0,like=0;
    int res1=0,res2=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            res1+=(a[i]==1);
            res2+=(b[i]==1);
        }
        else{
            dis+=(a[i]==-1);
            like+=(a[i]==1);
        }
    }
    int ans=-1e9;
    for(int i=-dis;i<=like;i++){
        ans=max(ans,min(res1+i,res2+(like-(i+dis))));
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
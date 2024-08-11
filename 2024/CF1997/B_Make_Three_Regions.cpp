#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<char> > a(3,vector<char>(n+10));
    for(int i=0;i<=1;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<=1;i++){
        for(int j=2;j<n;j++){
            if(a[i][j]=='.'){
                int ii=i^1;
                if(a[i][j-1]=='.'&&a[i][j+1]=='.'&&a[ii][j]=='.'&&a[ii][j-1]=='x'&&a[ii][j+1]=='x') ans++;
            }
        }
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
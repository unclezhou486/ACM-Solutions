#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > a((n+5),vector<int>(m+5));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch;
            cin>>ch;
            if(ch=='B') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1];
            ans+=a[i][j];
        }
    }
    for(int i=1;i<n;i++){
        bool flag=0;
        for(int j=1;j<m;j++){
            if(a[i][j]&&a[n][j]&&a[i][m]&&a[n][m]){
                ans--;
                flag=1;
                break;
            }
        }
        if(flag) break;
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
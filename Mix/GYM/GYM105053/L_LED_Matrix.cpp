#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<char> > a(n+1,vector<char>(m+1) ),b(n+1,vector<char>(k+1));
    vector<int> vis1(n+1),vis2(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='-') vis1[i]=1;
        }
        for(int j=1;j<=k;j++){
            cin>>b[i][j];
            if(b[i][j]=='*') vis2[i]=1;
        }
    }
    bool flag=1;
    for(int i=1;i<=n;i++){
        if(vis1[i]&&vis2[i]){
            flag=0;
        }
    }
    if(flag) cout<<"Y\n";
    else cout<<"N\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
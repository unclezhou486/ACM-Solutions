#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int> > a(n+1,vector<int>(m+1,0) );
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='x') a[i][j]=1e9;
            else if(c=='.') a[i][j]=1;
            //else if(c=='') a[i][j]=0;

        }
    }
    long long ans=1e9;
    for(int i=1;i<=n;i++){
        long long res=0;
        for(int j=1;j<min(k,m);j++){
            res+=a[i][j];
        }
        for(int j=k;j<=m;j++){
            res+=a[i][j];
            res-=a[i][j-k];
            ans=min(ans,res);
        }
    }
    for(int i=1;i<=m;i++){
        long long  res=0;
        for(int j=1;j<min(k,n);j++){
            res+=a[j][i];
        }
        for(int j=k;j<=n;j++){
            res+=a[j][i];
            res-=a[j-k][i];
            ans=min(ans,res);
        }
    }
    if(ans==1e9) cout<<-1<<'\n';
    else cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
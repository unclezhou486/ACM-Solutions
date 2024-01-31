#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=21;
const long long INF=1e18;
int n,m;

int a[N][N];
int s[N][N];

int dp[(1<<N)][21];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s[i][j]=1e18;
            if(i==j) s[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        s[u][v]=min(w,s[u][v]);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                s[j][k]=min(s[j][k],s[j][i]+s[i][k]);
            }
        }
    }
    //for(int i=1)
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j]=INF;
        }
    }
    for(int i=0;i<n;i++){
        dp[1<<i][i]=0;
    }
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                for(int k=0;k<n;k++){
                    if(dp[i-(1<<j)][k]==INF) continue;
                    if(k==j) continue;
                    if(s[k][j]==INF) continue;
                    dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k]+s[k][j]);
                }
            }
        }
    }
    long long ans=INF;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[(1<<n)-1][i]);
        //cout<<dp[(1<<n)-1][i]<<'\n';
    }
    if(ans!=INF) cout<<ans<<'\n';
    else cout<<"No\n";
}
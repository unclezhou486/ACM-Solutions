#include <bits/stdc++.h>

using namespace std;

//int a[1010][3];

//int dp[2][210][210][210];

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int> (3));
    int m=min(210,n+2);
    vector<vector<vector<vector<int>>>> dp(2, vector<vector<vector<int>>>(m, vector<vector<int>>(m, vector<int>(m))));
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    for(int i=0;i<n;i++){ //第i天
        for(int j=0;j<=min(i,202);j++){ //有连续j天无
            for(int k=0;k<=min(i,202);k++){ //有连续k天无
                int j1=j+(j!=0);
                int k1=k+(k!=0);
                int nxt=i&1^1;
                dp[nxt][1][j1][k1]=max(dp[nxt][1][j1][k1],dp[i&1][0][j][k]+a[i][0]-j-k);
                dp[nxt][1][j1][k1]=max(dp[nxt][1][j1][k1],dp[i&1][1][j][k]+a[i][0]-j-k);
                dp[nxt][2][1][k1]=max(dp[nxt][2][1][k1],dp[i&1][1][j][k]+a[i][1]-1-k);
                dp[nxt][2][j1][1]=max(dp[nxt][2][j1][1],dp[i&1][1][j][k]+a[i][2]-j-1);

                dp[nxt][j1][1][k1]=max(dp[nxt][j1][1][k1],dp[i&1][j][0][k]+a[i][1]-j-k);
                dp[nxt][1][2][k1]=max(dp[nxt][1][2][k1],dp[i&1][j][1][k]+a[i][0]-1-k);
                dp[nxt][j1][1][k1]=max(dp[nxt][j1][1][k1],dp[i&1][j][1][k]+a[i][1]-j-k);
                dp[nxt][j1][2][1]=max(dp[nxt][j1][2][1],dp[i&1][j][1][k]+a[i][2]-j-1);
                
                dp[nxt][j1][k1][1]=max(dp[nxt][j1][k1][1],dp[i&1][j][k][0]+a[i][2]-j-k);
                dp[nxt][1][k1][2]=max(dp[nxt][1][k1][2],dp[i&1][j][k][1]+a[i][0]-k-1);
                dp[nxt][j1][1][2]=max(dp[nxt][j1][1][2],dp[i&1][j][k][1]+a[i][1]-j-1);
                dp[nxt][j1][k1][1]=max(dp[nxt][j1][k1][1],dp[i&1][j][k][1]+a[i][2]-j-k);
            }
        }
    }
    int ans=0;
    for(int j=0;j<=min(202,n);j++){
        for(int k=0;k<=min(202,n);k++){
            ans=max(ans,dp[n&1][1][j][k]);
            ans=max(ans,dp[n&1][j][1][k]);
            ans=max(ans,dp[n&1][j][k][1]);
        }
    }
    cout<<ans<<'\n';
    //for(int i=0;i<=1;i++){
    //    for(int j=0;j<=min(n,202);j++){
    //        for(int k=0;k<=min(n,202);k++){
    //            dp[i][j][k][1]=dp[i][j][1][k]=dp[i][1][j][k]=0;
    //        }
    //    }
    //}
}
/*
1
3
1 1 10
1 10 1
10 1 1
*/


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
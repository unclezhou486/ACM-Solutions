#include <bits/stdc++.h>

using namespace std;

const int N=2e6+10;

int n,m;

int a[N];
long long dp[N][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=2*m;i++){
        dp[i][0]=dp[i][1]=1e18;
    }
    long long ans=1e18;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(x>=m){
            ans=min(ans,(long long)y);
        }
        if(x*2>=m){
            ans=min(ans,(long long)y/2);
        }
        for(int j=2*m;j>=x;j--){
            dp[j][0]=min(dp[j][0],dp[j-x][0]+y);
            dp[j][1]=min(dp[j][1],dp[j-x][1]+y);
            if(j>=x*2)dp[j][1]=min(dp[j][1],dp[j-x*2][0]+y/2);
        }
    }
    for(int i=m;i<=2*m;i++){
        ans=min(ans,dp[i][0]);
        ans=min(ans,dp[i][1]);
    }
    cout<<ans<<'\n';
}
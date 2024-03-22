#include <bits/stdc++.h>

using namespace std;

const int N=4e3+10;

int n,m,k,t;
int a[N][N];
int dp[N][N];

int main(){
    cin>>n>>m>>k>>t;
    for(int i=1;i<=k;i++){
        int x,y,v;
        cin>>x>>y>>v;
        a[x][y]=v;
    }
    for(int i=1;i<=n;i++){
        priority_queue<pair<int,int> > q;
        for(int j=1;j<=min(t,n);j++){
            q.push({dp[i-1][j],j});
        }
        for(int j=1;j<=m;j++){
            if(j+t<=m){
                q.push({dp[i-1][j+t],j+t});
            }
            while(q.size()&&q.top().second<j-t) q.pop();
            if(q.size())dp[i][j]=q.top().first+a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans=max(ans,dp[n][i]);
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=m;j++){
    //        cout<<dp[i][j]<<' ';
    //    }
    //    cout<<'\n';
    //}
    cout<<ans<<'\n';
    return 0;
}
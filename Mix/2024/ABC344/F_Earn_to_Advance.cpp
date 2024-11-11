#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=110;
const int INF=1e18;

int n;

int a[N][N],r[N][N],d[N][N];

pair<int,int> dp[N][N];
int dis[N][N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j],dp[i][j]={INF,0};
    for(int i=1;i<=n;i++) for(int j=1;j<n;j++) cin>>r[i][j];
    for(int i=1;i<n;i++) for(int j=1;j<=n;j++) cin>>d[i][j];
    dp[1][1]={0,0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=i;k++){
                for(int l=1;l<=j;l++){
                    dis[k][l]=INF;
                }
            }
            dis[i][j]=0;
            for(int k=i;k>=1;k--){
                for(int l=j;l>=1;l--){
                    if(k<i) dis[k][l]=min(dis[k][l],dis[k+1][l]+d[k][l]);
                    if(l<j) dis[k][l]=min(dis[k][l],dis[k][l+1]+r[k][l]);
                    int res=max(0ll,dis[k][l]-dp[k][l].second+a[k][l]-1)/a[k][l];
                    int t=dp[k][l].first+res+(i-k)+(j-l);
                    int v=dp[k][l].second+res*a[k][l]-dis[k][l];
                    if(t<dp[i][j].first||(t==dp[i][j].first&&v>dp[i][j].second)){
                        dp[i][j]={t,v};
                    }
                }
            }
        }
    }
    cout<<dp[n][n].first<<'\n';
}
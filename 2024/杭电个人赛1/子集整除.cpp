#pragma GCC O(2)
#pragma GCC O(3)
#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;

int n,k,p;

int a[N];

int dp[2][N];
int cnt[2][N];
bool v[2][N];

void solve(){
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int xx=(i-1)&1;
        int yy=(i)&1;
        for(int j=0;j<k;j++){
            if(v[xx][j]){
                v[yy][j]=1;
                dp[yy][j]=(dp[yy][j]+dp[xx][j])%p;
                cnt[yy][j]=(cnt[yy][j]+cnt[xx][j])%p;
                int res=j+a[i];
                int x=res/k;
                int y=res%k;
                v[yy][y]=1;
                dp[yy][y]=(dp[yy][y]+dp[xx][j]+((long long)(x)*cnt[xx][j]%p))%p;
                cnt[yy][y]=(cnt[yy][y]+cnt[xx][j])%p;
            }
        }
        int x=a[i]/k;
        int y=a[i]%k;
        dp[yy][y]=(dp[yy][y]+x)%p;
        cnt[yy][y]+=1;
        cnt[yy][y]%=p;
        v[yy][y]=1;
        for(int j=0;j<k;j++){
            v[xx][j]=0;
            dp[xx][j]=0;
            cnt[xx][j]=0;
        }
    }
    int ans=0;
    for(int i=0;i<k;i++){
        int yy=n&1;
        if(v[yy][i]){
            ans+=dp[yy][i];
            ans%=p;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
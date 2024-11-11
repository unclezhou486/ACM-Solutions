#include <bits/stdc++.h>

using namespace std;

const int N=2e3+10;

int n,m,k;
long double s;

long double a[N];

long double s1[N],s2[N];

long double dp[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k>>s;
    s/=2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n+1;i<=n+m;i++){
        cin>>a[i];
    }
    n=n+m;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s1[i]=a[i];
        s1[i]+=s1[i-1];
        s2[i]=a[i]*a[i];
        s2[i]+=s2[i-1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=1e18;
        }
    }
    dp[0][0]=0;
    long double ss=s*s;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            for(int q=0;q<k;q++){
                long double aa=(i-j);
                long double bb=-2*(s1[i]-s1[j]);
                long double del=(-bb)/(2*aa);
                dp[i][q+1]=min(dp[i][q+1],dp[j][q]+ss*(i-j)+s2[i]-s2[j]+del*del*(i-j)-2*del*(s1[i]-s1[j]));
            }
        }
    }
    cout<<fixed<<setprecision(8)<<dp[n][k]<<'\n';
}
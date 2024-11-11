#include <bits/stdc++.h>

using namespace std;

const int N=5e4+10;

int dp[510];

int a[N];
int n,c;

void solve(){
    memset(dp,-1,sizeof dp);
    //cout<<dp[1][1];
    cin>>n>>c;
    int ans=1e9;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0]=0;
    sort(a+1,a+1+n);
    //for(int i=1;i<=n;i++){
    //    cout<<a[i]<<' ';
    //}
    //cout<<'\n';
    for(int i=1;i<=n;i++){
        if(dp[c-a[i]]!=-1&&c-a[i])ans=min(ans,a[i]-dp[c-a[i]]);
        //dp[i][a[i]]=a[i];
        //dp[a[i]]=a[i];
        for(int j=c;j>=a[i];j--){
            //dp[i][j]=max(dp[i-1][j],dp[i][j]);
            dp[j]=max(dp[j-a[i]],dp[j]);
            //ans=min(ans,a[i]-dp[i][j]);
        }
        dp[a[i]]=a[i];
        
        if((c-a[i])==0) ans=0;
        //for(int j=0;j<=c;j++){
        //    cout<<dp[j]<<' ';
        //}
        //cout<<'\n';
    }
    
    //cout<<ans<<'\n';
    //if(ans==1e9) cout<<-1<<'\n';
    //else cout<<ans<<'\n';
    cout<<((ans==1e9)?-1:ans)<<'\n';
}

int main(){
    //freopen("1.out","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
4 22
1 2 16 9 

*/
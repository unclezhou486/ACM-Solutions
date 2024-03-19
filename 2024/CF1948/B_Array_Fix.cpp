#include <bits/stdc++.h>

using namespace std;

const int N=1e2+10;

int n,a[N];
int b[N];
bool dp[N][2];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]%10;
        dp[i][0]=dp[i][1]=0;
    }
    dp[0][0]=dp[0][1]=1;
    for(int i=1;i<=n;i++){
        if(a[i]>=a[i-1]){
            dp[i][0]|=dp[i-1][0];
        }
        if(a[i]>=b[i-1]){
            dp[i][0]|=dp[i-1][1];
        }
        if(a[i]>=10){
            if(a[i]/10<=(a[i]%10)){
                if(a[i]/10>=b[i-1]){
                    dp[i][1]|=dp[i-1][1];
                }
                if((a[i]/10)>=a[i-1]){
                    dp[i][1]|=dp[i-1][0];
                }
            }
        }
    }
    if(dp[n][0]||dp[n][1]){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
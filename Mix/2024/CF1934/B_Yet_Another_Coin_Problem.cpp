#include <bits/stdc++.h>

using namespace std;

int dp[200];
int a[5]={1,3,6,10,15};
void baoli(){
    for(int i=0;i<=100;i++){
        dp[i]=1e9;
    }
    dp[0]=0;
    for(int i=0;i<=100;i++){
        for(int j=0;j<5;j++){
            dp[i+a[j]]=min(dp[i+a[j]],dp[i]+1);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    if(n<=100){
        cout<<dp[n]<<'\n';
    }
    else{
        int res=n-100;
        int ress=res/15;
        int resss=res%15;
        cout<<dp[100+resss-15]+ress+1<<'\n';
    }
}


int main(){
    //freopen("1.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0),cout.tie(02);
    baoli();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
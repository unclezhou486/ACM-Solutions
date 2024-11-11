#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,l,r;
int a[N];
int dp[N];
int ans;
deque<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>l>>r;
    for(int i=0;i<=n;i++){
        cin>>a[i];
        dp[i]=-1e9;
    }
    dp[0]=0;
    ans=-1e9;
    for(int i=1;i<=n;i++){
        while(q.size()&&q.front()<i-r){
            q.pop_front();
        }
        if(q.size()) dp[i]=dp[q.front()]+a[i];
        while(q.size()&&dp[i-l+1]!=-1e9&&dp[i-l+1]>dp[q.back()]) q.pop_back();
        if(i-l+1>=0&&dp[i-l+1]!=-1e9) q.push_back(i-l+1);
        
    }
    for(int i=n-r+1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    //for(int i=1;i<=n;i++) cout<<dp[i]<<' ';
    //cout<<'\n';
    cout<<ans<<'\n';
}
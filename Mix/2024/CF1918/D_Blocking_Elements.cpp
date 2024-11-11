#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(int n,long long x,vector<int> s,vector<int> a){
    int st=0;
    vector<int> dp(n+1);
    vector<pair<int,int> > q(n+10);
    int h=1,t=0;
    q[++t]={0,0};
    for(int i=1;i<=n;i++){
        while(s[i-1]-s[q[h].first]>x){
            h++;
        }
        dp[i]=q[h].second+a[i];
        while(q[t].second>=dp[i]&&h<=t) t--;
        q[++t]={i,dp[i]};
        //for(int j=h;j<=t;j++){
        //    cout<<q[j].first<<','<<q[j].second<<' ';
        //}
        //cout<<'\n';
    }
    //for(int i=1;i<=n;i++){
        //cout<<dp[i]<<' '<<s[n]-s[i]<<'\n';
    //}
    for(int i=1;i<=n;i++){
        if(max(dp[i],s[n]-s[i])<=x) return 1;
    }
    return 0;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> s(n+1);
    int maxn=0;
    for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]),s[i]=a[i]+s[i-1];
    long long l=maxn,r=1e14;
    //cout<<check(n,13,s,a);
    //return;
    while(l<r){
        long long mid=(l+r)>>1;
        if(check(n,mid,s,a)) r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';
}

signed main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0),cout.tie(0);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
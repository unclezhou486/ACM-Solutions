#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;

int n,m,k,d;

int a[N];
int dp[N];
int ress[N];
void solve(){
    cin>>n>>m>>k>>d;
    vector<int> ve;
    int minn=0;
    int ans=1e18;
    for(int i=1;i<=n;i++){
        deque<pair<int,int> > q;
        for(int j=1;j<=m;j++){
            cin>>a[j];
            if(q.size()&&j-q.front().second>d+1) q.pop_front();
            if(q.size()) dp[j]=q.front().first+a[j]+1;
            else dp[j]=1;
            while(q.size()&&dp[j]<=q.back().first) q.pop_back();
            q.push_back({dp[j],j});
        }
        ress[i]=dp[m];
        minn+=ress[i];
        if(i>=k){
            minn-=ress[i-k];
            ans=min(ans,minn);
        }
        //cout<<ress[i]<<' ';
        ve.push_back(dp[m]);
    }

    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
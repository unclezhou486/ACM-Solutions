#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> w(n);
    vector<int> vec1,vec2;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==1){
            vec1.push_back(w[i]);
            vec2.push_back(0);
        }
        else vec2.push_back(w[i]),vec1.push_back(0);
    }
    auto ccf = [&] (vector<int> &vec,int x) -> int {
        int m=vec.size();
        vector<int> dp(m);
        int maxn=0;
        for(int i=0;i<=min(x,m-1);i++){
            dp[i]=vec[i];
        }
        for(int i=x+1;i<m;i++){
            //dp[i]=
            maxn=max(maxn,dp[i-x-1]);
            dp[i]=maxn+vec[i];
        }
        int res=0;
        for(int i=0;i<m;i++){
            //cout<<dp[i]<<' ';
            res=max(res,dp[i]);
        }
        //cout<<'\n';
        return res;
    };
    int ans=0;
    ans+=ccf(vec1,a);
    ans+=ccf(vec2,b);
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
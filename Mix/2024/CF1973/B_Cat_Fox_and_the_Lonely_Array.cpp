#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=1;
    for(int i=20;i>=0;i--){
        for(int j=1;j<=n;j++){
            dp[j]=(a[j]>>i)&1;
        }
        vector<int> vec;
        for(int j=1;j<=n;j++){
            if(dp[j]) vec.push_back(j);
        }
        if(vec.size()){
            res=max(res,vec[0]);
            res=max(res,n-vec[vec.size()-1]+1);
            for(int i=1;i<vec.size();i++){
                res=max(res,vec[i]-vec[i-1]);
            }
        }
        else{
            continue;
        }
    }
    cout<<res<<'\n';
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
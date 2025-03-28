#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+10);
    // vector<vector<int> > id0(n+10,vector<int>(30)),id1(n+10,vector<int>(30));
    // vector<int> bit(30);
    vector<int> vis(30);
    vector<long long> dp(n+10,-1e18);
    vector<int> g(1<<m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<(1<<m);i++){
        cin>>g[i];
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            vector<int> bit(30);
            for(int k=j;k<=i;k++){
                for(int l=0;l<m;l++){
                    if((a[k]>>l)&1){
                        bit[l]|=2;
                    }
                    else{
                        bit[l]|=1;
                    }
                }
            }
            int res=0;
            for(int k=0;k<m;k++){
                if(bit[k]==3){
                    res+=(1<<k);
                }
            }
            dp[i]=max(dp[i],dp[j-1]+g[res]);
        }
        cout<<dp[i]<<" \n"[i==n];
    }
    cout<<dp[n]<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

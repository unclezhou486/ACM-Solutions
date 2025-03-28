#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+10);
    vector<vector<int> > id0(n+10,vector<int>(30)),id1(n+10,vector<int>(30));
    vector<int> bit(30);
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
        for(int j=0;j<m;j++){
            bit[j]=(a[i]>>j)&1;
            vis[j]=0;
            // cout<<bit[j]<<" \n"[j==m-1];
        }
        dp[i]=dp[i-1]+g[0];
        int id=i-1;
        // cout<<"CCF:"<<i<<'\n';
        while(id>=1){
            int idd=id;
            id=1;
            for(int j=0;j<m;j++){
                if(vis[j]) continue;
                if(bit[j]==1){
                    id=max(id,id0[idd][j]);
                }       
                else{
                    id=max(id,id1[idd][j]);
                }
            }
            int ress=0;
            for(int j=0;j<m;j++){
                if(vis[j]) ress+=(1<<j);
            }
            dp[i]=max(dp[i],dp[id]+g[ress]);
            int res=0;
            for(int j=0;j<m;j++){
                if(((a[id]>>j)&1)!=bit[j]){
                    vis[j]=1;
                }
                if(vis[j]){
                    res+=(1<<j);
                }
            }
            // cout<<"ID:"<<' '<<"RES"<<'\n';
            // cout<<id<<' '<<res<<'\n';
            // cout<<"VIS:\n";
            // for(int j=0;j<m;j++){
                // cout<<vis[j]<<" \n"[j==m-1];
            // }
            dp[i]=max(dp[i],dp[id-1]+g[res]);
            id=id-1;
        }
        for(int j=0;j<m;j++){
            if(bit[j]==1) id1[i][j]=i,id0[i][j]=id0[i-1][j];
            else id0[i][j]=i,id1[i][j]=id1[i-1][j];
        }
        cout<<dp[i]<<" \n"[i==n];
    }
    // cout<<dp[3]<<'\n';
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

//-1 -2 1 3
//1 1 3 2 2
//-2 -2 10 8 8
//8

/*

1
5 2
1 3 2 2 3
-8 6 2 -8

-8 2 -2 -2 8

*/
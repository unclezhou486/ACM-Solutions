#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

bool dp[N][N];

int n;

int change(int x,int k){
    int res=(x+k+n)%n;
    if(!res) res=n;
    return res;
}


void solve(){
    int m,x;
    cin>>n>>m>>x;
    for(int i=0;i<=m;i++) for(int j=1;j<=n;j++) dp[i][j]=0;
    dp[0][x]=1;
    for(int i=1;i<=m;i++){
        int d;
        char op;
        cin>>d>>op;
        if(op=='0'){
            for(int j=1;j<=n;j++){
                if(dp[i-1][j]) dp[i][change(j,d)]=1;
            }
        }
        else if(op=='1'){
            for(int j=1;j<=n;j++){
                if(dp[i-1][j]) dp[i][change(j,-d)]=1;
            }
        }
        else{
            for(int j=1;j<=n;j++){
                if(dp[i-1][j]) dp[i][change(j,d)]=1,dp[i][change(j,-d)]=1;
            }
        }
    }
    int ans=0;
    queue<int> q;
    for(int i=1;i<=n;i++) if(dp[m][i]) ans++,q.push(i);
    cout<<ans<<'\n';
    while(q.size()){
        cout<<q.front()<<' ';;
        q.pop();
    }
    cout<<'\n';
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
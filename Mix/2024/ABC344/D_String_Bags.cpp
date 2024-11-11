#include <bits/stdc++.h>

using namespace std;

const int N=110;

int dp[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;
    string t;
    cin>>t;
    t='0'+t;
    int lent=t.size();
    int n;
    cin>>n;
    int m;
    for(int ii=1;ii<=n;ii++){
        cin>>m;
        while(m--){
            string res;
            cin>>res;
            int lens=res.size();
            for(int i=1;i+lens-1<lent;i++){
                bool fl=1;
                for(int j=i;j<=i+lens-1;j++){
                    if(t[j]!=res[j-i]) fl=0;
                }
                if(fl){
                    dp[ii][i+lens-1]=min(dp[ii][i+lens-1],dp[ii-1][i-1]+1);
                }
            }
        }
        for(int i=0;i<lent;i++){
            dp[ii][i]=min(dp[ii][i],dp[ii-1][i]);
        }
    }
    //cout<<dp[2][3]<<' '<<dp[3][5];
    if(dp[n][lent-1]!=0x3f3f3f3f) cout<<dp[n][lent-1]<<'\n';
    else cout<<-1<<'\n';
}
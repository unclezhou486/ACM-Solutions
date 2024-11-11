#include <bits/stdc++.h>

using namespace std;

const int N=2e3+10;

int n,p;
int dp[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>p;
    for(int i=1;i<=p;i++){
        dp[i]=1e9;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int res=x%p;
        if(!res) res=p;
        dp[res]=1;
    }
    for(int i=1;i<=p;i++){
        bool fl=0;
        //while(fl)
        do{
            fl=0;
            for(int j=1;j<p;j++){
            int res=j+i;
            res%=p;
            if(!res) res=p;
            if(dp[res]>dp[j]+dp[i]){
                dp[res]=dp[j]+dp[i];
                fl=1;
            }
            //dp[res]=min(dp[res],dp[j]+dp[i]);
        }
        }while(fl);
        
    }
    cout<<dp[p]<<'\n';
}
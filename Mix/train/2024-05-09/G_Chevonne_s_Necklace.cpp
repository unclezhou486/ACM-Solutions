#include <bits/stdc++.h>

using namespace std;

const int N=2e3+10;
const int mod=998244353;
int n;

int a[N];

int dp[N];
bool v[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0]=1;
    v[0]=1;
    for(int i=1;i<=n;i++){
        if(!a[i]) continue;
        for(int j=n;j>=a[i];j--){
            if(v[j-a[i]]) v[j]=1;
            dp[j]+=dp[j-a[i]];
            dp[j]%=mod;
        }
    }
    //for(int i=0;i<=n;i++){
    //    cout<<dp[i]<<'\n';
    //}
    int ansval,ansnum;
    for(int i=n;i>=0;i--){
        if(v[i]){
            ansval=i;
            ansnum=dp[i];
            break;
        }
    }
    cout<<ansval<<" "<<ansnum<<'\n';
}
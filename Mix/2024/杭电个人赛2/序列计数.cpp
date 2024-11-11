#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod=998244353;

long long qmi(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

int mo(int x){
    return ((x%mod)+mod)%mod;
}

void solve(){
    int n,m;
    cin>>n>>m;
    int res=1;
    //int x=n/i;
    int x=n;
    for(int i=2;i<=x/i;i++){
        int cnt=0;
        int ress=1;
        while(n%i==0){
            n/=i;
            cnt++;
            //ress*=i;
        }        
        if(cnt){
            res*=mo(qmi(cnt+1,m)-qmi(cnt,m));
            res%=mod; 
        }
    }
    if(n!=1){
        res*=mo(qmi(2,m)-1);
        res%=mod;
    }
    cout<<res<<'\n';
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
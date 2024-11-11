#include <bits/stdc++.h>

const int mod=998244353;

long long MOD(long long x){
    return((x%mod)+mod)%mod;
}

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<long long > cnt0(n+1),cnt1(n+1);
    std::vector<long long> sum1(n+1),sum0(n+1);
    std::vector<long long >ans(n+1);
    for(int i=1;i<=n;i++){
        char ch;
        std::cin>>ch;
        if(ch=='1'){
            cnt1[i]=1;
            sum1[i]=i;
            ans[i]=ans[i-1]+cnt0[i-1]*i-sum0[i-1];
            ans[i]%=mod;
        }
        else{
            cnt0[i]=1;
            sum0[i]=i;
            ans[i]=ans[i-1]+cnt1[i-1]*i-sum1[i-1];
            ans[i]%=mod;
        }
        cnt1[i]+=cnt1[i-1],cnt0[i]+=cnt0[i-1];
        sum1[i]+=sum1[i-1],sum0[i]+=sum0[i-1];
        sum1[i]=MOD(sum1[i]),sum0[i]=MOD(sum0[i]);
    }
    while(m--){
        long long l,r;
        std::cin>>l>>r;
        long long res=ans[r]-ans[l-1];
        res=MOD(res);
        res-=cnt0[l-1]*(sum1[r]-sum1[l-1]-(cnt1[r]-cnt1[l-1])*l);
        res=MOD(res);
        res-=cnt1[l-1]*(sum0[r]-sum0[l-1]-(cnt0[r]-cnt0[l-1])*l);
        res=MOD(res);
        res-=(cnt0[r]-cnt0[l-1])*(l*cnt1[l-1]-sum1[l-1]);
        res=MOD(res);
        res-=(cnt1[r]-cnt1[l-1])*(l*cnt0[l-1]-sum0[l-1]);
        res=MOD(res);
        std::cout<<res<<'\n';
    }
    return;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
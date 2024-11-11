#include <bits/stdc++.h>
#define int long long
const int mod=1e9+7;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> vec(n+1);
    std::vector<int> shi(m+1);
    std::vector<int> jie(n+1);
    for(int i=1;i<=n;i++){
        char ch;
        std::cin>>ch;
        vec[i]=ch-'0';
    }
    shi[0]=1;
    for(int i=1;i<=m;i++){
        shi[i]=shi[i-1]*10;
        shi[i]%=mod;
    }
    jie[0]=1;
    for(int i=1;i<=n;i++){
        jie[i]=jie[i-1]*i;
        jie[i]%=mod;
    }
    auto qmi = [&] (long long a,long long b) -> long long {
        long long res=1;
        while(b){
            if(b&1) res=res*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return res;
    };
    auto inv = [&] (long long x) -> long long {
        return qmi(x,mod-2);
    };
    auto C = [&] (long long nn,long long mm) -> long long {
        if(nn<mm){
            return 0;
        }
        else{
            long long res=jie[nn];
            res=res*inv(jie[mm]);res%=mod;
            res=res*inv(jie[nn-mm]);res%=mod;
            return res;
        }
    };
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long res=0;
        for(int k=m-1;~k;k--){
            res=C(i-1,m-1-k)*vec[i]*shi[k];res%=mod;
            res*=C(n-i,k),res%=mod;
            ans+=res;
            ans%=mod;
            //std::cout<<res<<' ';
        }
        //ans+=res;
        //std::cout<<ans<<'\n';
    }
    std::cout<<ans<<'\n';
}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    solve();
    return 0;
}
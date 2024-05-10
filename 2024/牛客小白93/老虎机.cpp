#include <bits/stdc++.h>

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

long long inv(long long x){
    return qmi(x,mod-2);
}

void solve(){
    int m,a,b,c;
    std::cin>>m>>a>>b>>c;
    long long ans=0;
    if(m==1){
        ans=c;
        //std::cout<<c<<'\n';
    }
    else{
        long long res=0;
        res=1*inv(m)*inv(m);
        res%=mod;
        res*=c;
        res%=mod;
        ans+=res;
        res=inv(m)*inv(m);
        res%=mod;
        res=res*3*(m-1); res%=mod;
        res*=b;res%=mod;
        ans+=res;
        res=0;
        res=(m-1)*(m-2);
        res%=mod;
        res*=inv(m),res%=mod;
        res*=inv(m),res%=mod;
        res*=a;
        res%=mod;
        ans+=res;
        ans%=mod;
    }
    std::cout<<ans%mod<<'\n';
}


int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    //t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
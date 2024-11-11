#include <bits/stdc++.h>

const int mod=1e9+7;

long long dp[100][100];

long long qmi(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

long long inv2=qmi(2,mod-2);

long long f(long long x,long long y){
    if(!x) return 3*y;
    if(!y) return 3*x;
    if(dp[x][y]) return dp[x][y];
    dp[x][y]=(f(x-1,y)+f(x,y-1))*inv2%mod+3*inv2%mod;
    dp[x][y]%=mod;
    return dp[x][y];
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    long long x;
    std::cin>>x;
    int c2=0,c3=0;
    while(x%2==0) c2++,x/=2;
    while(x%3==0) c3++,x/=3;
    if(x!=1) std::cout<<-1<<'\n';
    else std::cout<<f(c2,c3)<<'\n';
    return 0;
}
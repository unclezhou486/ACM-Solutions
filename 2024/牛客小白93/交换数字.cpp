#include <bits/stdc++.h>

const int N=2e5+10;
const int mod=998244353;
//string s1,s2;

void solve(){
    int n;
    std::cin>>n;
    std::vector<char> a(n),b(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    for(int i=0;i<n;i++){
        std::cin>>b[i];
        if(b[i]>a[i]) std::swap(a[i],b[i]);
    }
    long long aa=0,bb=0;
    for(int i=0;i<n;i++){
        //std::cout<<aa<<' '<<bb<<'\n';
        aa*=10;
        aa+=(a[i]-'0');
        bb*=10;
        bb+=(b[i]-'0');
        aa%=mod;
        bb%=mod;
    }
    std::cout<<aa*bb%mod<<'\n';
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    //std::cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

const int mod=1e9+7;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin>>n;
    std::vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    int id=1;
    std::string s;
    std::cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='R'){
            id=std::min(n,id+1);
        }
        else id=std::max(1,id-1);
        ans+=a[id];
        ans%=mod;
    }
    std::cout<<ans<<'\n';
}
#include <bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin>>n;
    std::vector<long long> a(n+1);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    if(n%2){
        long long maxn=0,minn=1e18;
        long long ans=2e18;
        for(int i=1;i<=n/2;i++){
            minn=std::min(minn,a[i]*a[n-i]);
            maxn=std::max(maxn,a[i]*a[n-i]);
        }
        minn=std::min(minn,a[n]);
        ans=std::min(ans,maxn-minn);
        std::cout<<ans<<'\n';
    }
    else{
        long long maxn=0,minn=1e18;
        long long ans=2e18;
        for(int i=1;i<=n/2;i++){
            minn=std::min(minn,a[i]*a[n-i+1]);
            maxn=std::max(maxn,a[i]*a[n-i+1]);
        }
        ans=std::min(ans,maxn-minn);
        std::cout<<ans<<'\n';        
    }
}
#include <bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n,m;
    std::cin>>n>>m;
    std::vector<long long > b(m+1);
    std::vector<std::vector<long long> > a(n+1,std::vector<long long>(m+1));
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cin>>a[i][j];
            b[j]+=a[i][j];
            ans=std::max(ans,b[j]);
        }
    }
    std::cout<<ans<<'\n';

}
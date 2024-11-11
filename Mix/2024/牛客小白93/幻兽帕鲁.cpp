#include <bits/stdc++.h>
#define int long long

int n,m;

int check(int x,int nn){
    if(nn==n) return x;
    int res=(1ll<<nn);
    int ress=(1ll<<(nn+1));
    int y=(x-1)/ress*ress;
    if(x<=y+res) x=y+(x-y)*2-1;
    else x-=res,x=y+(x-y)*2;
    return check(x,nn+1);
}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    //int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x;
        std::cin>>x;
        x++;
        std::cout<<check(x,0)-1<<'\n';
    }
    return 0;
}
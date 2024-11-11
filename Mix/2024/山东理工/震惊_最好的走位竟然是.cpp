#include <bits/stdc++.h>

int cnt=0;
const int mod=998244353;

std::map<std::pair<int,int>,int> ma;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n,m,x,y;
    std::cin>>n>>m>>x>>y;
    std::vector<char> str(n+1);
    std::map<std::pair<int,int>,int> st,dp;
    for(int i=1;i<=n;i++) std::cin>>str[i];
    for(int i=1;i<=m;i++){
        int xx,yy;
        std::cin>>xx>>yy;
        st[{xx,yy}]=1;
    }
    std::queue<std::pair<int,int> > q;
    dp[{x,y}]=1;
    q.push({x,y});
    for(int i=1;i<=n;i++){
        std::map<std::pair<int,int>,int> res;
        while(q.size()){
            std::pair<int,int> pos=q.front();
            q.pop();
            int dx=0,dy=0;
            if(str[i]=='L') dx=-1;
            else if(str[i]=='U') dy=1;
            else if(str[i]=='R') dx=1;
            else dy=-1;
            int xx=pos.first,yy=pos.second;
            (res[{xx,yy}]+=dp[{xx,yy}])%=mod;
            if(!st[{xx+dx,yy+dy}])(res[{xx+dx,yy+dy}]+=dp[{xx,yy}])%=mod;
            else (res[{xx,yy}]+=dp[{xx,yy}])%=mod;
        }
        for(auto [a,b]:res){
            dp[a]=b;
            q.push(a);
        }
    }
    std::cout<<dp[{x,y}]<<'\n';
}
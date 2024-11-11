#include <bits/stdc++.h>

using namespace std;
const int N=(1<<9)+7;

int n,k;

vector<int> sta;
vector<int> st[N];
int cnt[N];
long long dp[11][100][N];
int lowbit(int x){return x&-x;}

bool check(int x){
    while(x){
        if(lowbit(x-lowbit(x))==(lowbit(x)<<1)) return 0;
        x-=lowbit(x);
    }
    return 1;
}

int count(int x){
    int res=0;
    while(x){
        res++;
        x-=lowbit(x);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<(1<<n);i++){
        if(check(i)){
            cnt[i]=count(i);
            sta.push_back(i);
        }
    }
    for(auto u:sta){
        for(auto v:sta){
            if(!(u&v)&&check(u|v)){
                st[u].push_back(v);
            }
        }
    }
    dp[0][0][0]=1;
    for(int i=1;i<=n+1;i++){
        for(int j=0;j<=k;j++){
            for(auto u:sta){
                for(auto v:st[u]){
                    int c=cnt[v];
                    if(j>=c) dp[i][j][u]+=dp[i-1][j-c][v];
                }
            }
        }
    }
    cout<<dp[n+1][k][0]<<'\n';
}
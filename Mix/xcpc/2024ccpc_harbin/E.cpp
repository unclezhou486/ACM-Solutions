#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=505;

int v[N],x[N];
struct fs{
    int fz,fm;
    bool operator<(const fs& a)const{
        return fz*a.fm<a.fz*fm;
    }
}t[N][N];
int n,m;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=m;i++)cin>>v[i];
    for(int i=1;i<=n;i++){
        for(int u=1;u<=m;u++){
            int _=gcd(x[i],v[u]);
            t[i][u]={x[i]/_,v[u]/_};
        }
    }
    for(int i=1;i<=n;i++){
        for(int u=1;u<=m;u++){
            vector<int> num(n+1);
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                auto it=upper_bound(t[j]+1,t[j]+m+1,t[i][u]);
                num[j]=it-t[j]+1;
            }
            vector<int> dp(n+1,-1);
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                if()
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
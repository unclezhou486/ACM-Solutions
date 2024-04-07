#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+10;
const int mod=1e9+7;

int n,m,k;

int e[N<<1],ne[N<<1],h[N<<1],idx;

int cnt[N<<1];

void add(int x,int y){e[++idx]=y,ne[idx]=h[x],h[x]=idx;}

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

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int u,v;
        cin>>u>>v;
        cnt[u]+=1;
        cnt[v+n]+=1;
        add(u,v+n);
        add(v+n,u);
    }
    for(int i=1;i<=n+m;i++){
        cnt[i]=(1-inv(cnt[i]));
        cnt[i]+=mod;
        cnt[i]%=mod;
        //cout<<cnt[i]<<' ';
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int res=1;
        for(int j=h[i];j;j=ne[j]){
            int x=e[j];
            res*=cnt[x];
            res%=mod;
            //cout<<i<<' '<<x<<' '<<' '<<cnt[x]<<' '<<res<<'\n';
        }
        res=1-res;
        res+=mod;
        res%=mod;
        ans+=res;
        ans%=mod;
    }
    cout<<"modint\n";
    cout<<ans<<' ';
    ans=0;
    for(int i=n+1;i<=n+m;i++){
        int res=1;
        for(int j=h[i];j;j=ne[j]){
            int x=e[j];
            res*=cnt[x];
            res%=mod;
        }
        res=1-res;
        res+=mod;
        res%=mod;
        ans+=res;
        ans%=mod;
    }
    cout<<ans<<' ';
}
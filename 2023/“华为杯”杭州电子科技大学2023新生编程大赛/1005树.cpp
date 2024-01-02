#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int e[N<<1],ne[N<<1],h[N],w[N<<1],idx;
int t,n;
int a[N];
int b[N][40];

void dfs(int x,int fa){
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        a[j]=a[x]^w[i];
        dfs(j,x);
    }
}

void add(int x,int y,int z){
    e[++idx]=y,ne[idx]=h[x],h[x]=idx,w[idx]=z;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        memset(h,0,sizeof h);
        memset(b,0,sizeof b);
        memset(a,0,sizeof a);
        idx=0;
        cin>>n;
        for(int i=1;i<n;i++){
            int u,v,w;
            cin>>u>>v>>w;
            add(u,v,w);
            add(v,u,w);
        }
        dfs(1,1);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=30;j++){
                if((a[i]>>j)&1) b[i][j]++;
                b[i][j]+=b[i-1][j];
            }
        }
        //for(int i=1;i<=n;i++){
        //    for(int j=0;j<=3;j++){
        //        cout<<b[i][j]<<' ';
        //    }
        //    cout<<'\n';
        //}
        //cout<<'\n';
        int q;
        cin>>q;
        while(q--){
            int l,r,x;
            cin>>l>>r>>x;
            x=a[x];
            long long res=0;
            for(int i=0;i<=30;i++){
                int res1=b[r][i]-b[l-1][i];
                int res2=r-l+1-res1;
                if((x>>i)&1){
                    res+=res2*(1<<i);
                }
                else{
                    res+=res1*(1<<i);
                }             
            }
            cout<<res<<'\n';
        }
    }
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=5e5+10;
const int INF=1e18;
int n,m;

int f[N];

struct node{
    int u,v,w;
}a[N];

int e[N],ne[N],w[N],h[N],idx;
int dep[N];
bool v[N];
int dp[N][22][2];
int fa[N][22];
void add(int x,int y,int z){
    e[++idx]=y,ne[idx]=h[x],h[x]=idx,w[idx]=z;
}

bool cmp(node a,node b){
    return a.w<b.w;
}

int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}

void dfs(int x,int faa){
    dep[x]=dep[faa]+1;
    fa[x][0]=faa;
    for(int i=1;i<=21;i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
        dp[x][i][0]=max(dp[x][i-1][0],dp[fa[x][i-1]][i-1][0]);
        dp[x][i][1]=max(dp[x][i-1][1],dp[fa[x][i-1]][i-1][1]);
    }
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        if(j==faa) continue;
        dp[j][0][w[i]%2]=w[i];
        dp[j][0][(w[i]%2)^1]=-INF;
        dfs(j,x);
    }
}

pair<int,int> lca(int x,int y){
    int ans1=-INF,ans0=-INF;
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=21;i>=0;i--){
        if(dep[fa[x][i]]>=dep[y]){
            
            ans1=max(ans1,dp[x][i][1]);
            ans0=max(ans0,dp[x][i][0]);
            x=fa[x][i];
            //cout<<ans0<<' '<<ans1<<'\n';
        }
    }
    if(x==y){
        return {ans0,ans1};
    }
    for(int i=21;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            ans1=max({ans1,dp[x][i][1],dp[y][i][1]});
            ans0=max({ans0,dp[y][i][0],dp[x][i][0]});
            x=fa[x][i],y=fa[y][i];
            //cout<<ans0<<' '<<ans1<<'\n';
        }
    }
    //cout<<x<<' '<<y<<'\n';
    ans1=max({ans1,dp[x][0][1],dp[y][0][1]});
    ans0=max({ans0,dp[x][0][0],dp[y][0][0]});
    return {ans0,ans1};
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=idx;i++){
        e[idx]=0,ne[idx]=0,w[idx]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=21;j++){
            dp[i][j][0]=dp[i][j][1]=-INF;
            fa[i][j]=0;
        }
        h[i]=0;
        f[i]=i;
    }
    idx=0;
    for(int i=1;i<=m;i++){
        v[i]=0;
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+1+m,cmp);
    int res=0,cnt=0;
    for(int i=1;i<=m;i++){
        int uu=find(a[i].u),vv=find(a[i].v);
        if(uu!=vv){
            cnt++;
            v[i]=1;
            add(a[i].u,a[i].v,a[i].w);
            add(a[i].v,a[i].u,a[i].w);
            f[uu]=vv;
            res+=a[i].w;
            //cnt++;
        }
    }
    //cout<<cnt<<'\n';
    if(cnt!=n-1){
        cout<<-1<<' '<<-1<<'\n';
        return;
    }
    //cout<<"CCF";
    int ans1=-1,ans0=-1;
    if(res%2) ans1=res;
    else ans0=res;
    //cout<<ans0<<' '<<ans1<<'\n';
    dfs(1,0);
    //cout<<dp[5][0][0]<<'\n';
    int ress=1e18;
    for(int i=1;i<=m;i++){
        if(v[i]) continue;
        int uu=a[i].u,vv=a[i].v;
        auto pos=lca(uu,vv);
        int res0=pos.first,res1=pos.second;
        //cout<<uu<<' '<<vv<<' '<<res0<<' '<<res1<<'\n';
        if(a[i].w%2){
            ress=min(ress,res+a[i].w-res0);
        }
        else{
            ress=min(ress,res+a[i].w-res1);
        }
    }
    if(ress!=1e18){
        if(ress%2){
            ans1=ress;
        }
        else{
            ans0=ress;
        }
    }
    cout<<ans0<<' '<<ans1<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
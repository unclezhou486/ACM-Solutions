#include <bits/stdc++.h>

using namespace std;

const int N=2e6+10;

int n;

int c[N];

int ma[N];

int e[N],ne[N],h[N],idx;
int la[N];
int siz[N],dfn[N],cnt;

void add(int x,int y){e[++idx]=y,ne[idx]=h[x],h[x]=idx;}

struct node{
    int id,col;
}b[N];


void dfs(int x){
    dfn[x]=++cnt;
    siz[dfn[x]]=1;
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        dfs(j);
        siz[dfn[x]]+=siz[dfn[j]];
    }
}

bool cmp(node a,node b){
    return a.id<b.id;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        add(x,i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        //cout<<i<<' '<<dfn[i]<<'\n';
        b[i].id=dfn[i];
        b[i].col=c[i];
    }
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++){
        ma[i]=max(ma[i-1],la[b[i].col]);
        la[b[i].col]=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=i,r=i+siz[i]-1;
        //cout<<l<<' '<<r<<' '<<ma[r]<<'\n';
        if(ma[r]<l) ans++;
    }
    cout<<ans<<'\n';
}
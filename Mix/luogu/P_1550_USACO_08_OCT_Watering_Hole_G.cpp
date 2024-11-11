#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n;

struct node{
    int l,r,x;
}a[N];
int cnt;
int f[N];

int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}

bool cmp(node a,node b){
    return a.x<b.x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[++cnt]={i,0,x};
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            a[++cnt]={i,j,w};
        }
        //int u,v,w;
        //cin>>u>>v>>w;
        //a[++cnt]={u,v,w};
    }
    sort(a+1,a+1+cnt,cmp);
    int ans=0;
    for(int i=1;i<=cnt;i++){
        int u=a[i].l,v=a[i].r;
        if(find(u)!=find(v)){
            ans+=a[i].x;
            f[find(u)]=v;
        }
    }
    cout<<ans<<'\n';
}
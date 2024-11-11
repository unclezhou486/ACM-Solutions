#include <bits/stdc++.h>

using namespace std;

const int N=1e4+10;

int b[N],cnt;
int dis[N];
int f[N];

struct node{
    int u,v,op;
}a[N];

//int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

int find(int x){
    if(f[x]==x) return f[x];
    int root=find(f[x]);
    dis[x]^=dis[f[x]];
    return f[x]=root;
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v;
        a[i].u--;
        b[++cnt]=a[i].u,b[++cnt]=a[i].v;
        string str;
        cin>>str;
        if(str=="even") a[i].op=0;
        else a[i].op=1;
    }
    sort(b+1,b+1+cnt);
    int res=unique(b+1,b+1+cnt)-(b+1);
    for(int i=1;i<=m;i++){
        a[i].u=lower_bound(b+1,b+1+res,a[i].u)-b;
        a[i].v=lower_bound(b+1,b+1+res,a[i].v)-b;
    }
    for(int i=1;i<=res;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        int x=a[i].u,y=a[i].v,xx=find(a[i].u),yy=find(a[i].v);
        if(xx==yy){
            if((dis[x]^dis[y])!=a[i].op){
                cout<<i-1<<'\n';
                return;
            }
        }
        else{
            f[xx]=yy;
            dis[xx]=dis[x]^dis[y]^a[i].op;
        }
    }
    cout<<m<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
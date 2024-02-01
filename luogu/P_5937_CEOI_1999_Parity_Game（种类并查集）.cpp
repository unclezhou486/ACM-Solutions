#include <bits/stdc++.h>

using namespace std;

const int N=1e4+10;

int n,m;
int cnt;
int b[N];
int f[N];
struct node{
    int u,v;
    string str;
}a[N];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].str;
        a[i].u--;
        b[++cnt]=a[i].u,b[++cnt]=a[i].v;
    }
    sort(b+1,b+1+cnt);
    int res=unique(b+1,b+1+cnt)-(b+1);
    for(int i=1;i<=m;i++){
        a[i].u=lower_bound(b+1,b+1+res,a[i].u)-b;
        a[i].v=lower_bound(b+1,b+1+res,a[i].v)-b;
    }
    for(int i=1;i<=2*res;i++){
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        if(a[i].str=="even"){
            if(find(a[i].u)==find(a[i].v+res)||find(a[i].u+res)==find(a[i].v)){
                cout<<i-1<<'\n';
                return;
            }
            f[find(a[i].u)]=find(a[i].v);
            f[find(a[i].u+res)]=find(a[i].v+res);
        }
        else{
            if(find(a[i].u)==find(a[i].v)||find(a[i].u+res)==find(a[i].v+res)){
                cout<<i-1<<'\n';
                return;
            }
            f[find(a[i].u)]=f[find(a[i].v+res)];
            f[find(a[i].u+res)]=f[find(a[i].v)];
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
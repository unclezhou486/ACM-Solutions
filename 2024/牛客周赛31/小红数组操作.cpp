#include <bits/stdc++.h>

using namespace std;

const int N=4e5+10;

int q,n;

int x[N],y[N],op[N];
int b[N];
int l[N],r[N];
map<int,int> ma;
int a[N];

int cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>op[i]>>x[i];
        if(!ma.count(x[i])) ma[x[i]]=++n;
        if(op[i]==1) {cin>>y[i];if(!ma.count(y[i]))ma[y[i]]=++n;}
    }
    for(int i=1;i<=q;i++){
        if(op[i]==1){
            int u=ma[x[i]],v=ma[y[i]];
            int uu=r[v];
            a[u]=x[i],a[v]=y[i];
            //l[r[v]]=u;
            //r[u]=r[v];
            //r[v]=u;
            //l[u]=v;
            l[uu]=u;
            r[u]=uu;
            l[u]=v;
            r[v]=u;
            cnt++;
        }
        else{
            cnt--;
            int u=ma[x[i]];
            r[l[u]]=r[u];
            l[r[u]]=l[u];
        }
    }
    int u=ma[0];
    cout<<cnt<<'\n';
    for(int i=1;i<=cnt;i++){
        cout<<a[r[u]]<<' ';
        u=r[u];
    }
}
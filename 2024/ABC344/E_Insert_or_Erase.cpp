#include <bits/stdc++.h>

using namespace std;

const int N=4e5+10;

int n,q;
int a[N];
int l[N],r[N];
int op[N],x[N],y[N];

map<int,int> ma;
int b[N<<1],cnt;

void add(int x){
    if(!ma.count(x)){
        ma[x]=++cnt;
        b[cnt]=x;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=0;
    a[n+1]=2e9;
    add(a[n+1]);
    add(a[0]);
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>op[i]>>x[i];
        if(op[i]==1) cin>>y[i];
    }
    for(int i=1;i<=n;i++){
        add(a[i]);
    }
    for(int i=1;i<=q;i++){
        add(x[i]);
        if(op[i]==1) add(y[i]);
    }
    for(int i=1;i<=n;i++) a[i]=ma[a[i]];
    for(int i=1;i<=q;i++){
        x[i]=ma[x[i]];
        if(op[i]==1) y[i]=ma[y[i]];
    }
    a[0]=ma[a[0]];
    a[n+1]=ma[a[n+1]];
    r[a[0]]=a[1];
    l[a[n+1]]=a[n];
    for(int i=1;i<=n;i++){
        l[a[i]]=a[i-1];
        r[a[i]]=a[i+1];
    }
    for(int i=1;i<=q;i++){
        if(op[i]==1){
            int xx=x[i];
            int yy=y[i];
            int rr=r[xx];
            r[xx]=yy;
            l[yy]=xx;
            r[yy]=rr;
            l[rr]=yy;
        }
        else{
            int xx=x[i];
            int ll=l[xx],rr=r[xx];
            r[ll]=rr;
            l[rr]=ll;
        }
    }
    int xx=r[a[0]];
    while(xx!=a[n+1]){
        cout<<b[xx]<<' ';
        xx=r[xx];
    }
}
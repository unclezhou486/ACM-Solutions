#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int cnt;
int n;
int root[N];
int a[N];
struct segmentTree{
    int l,r,ls,rs;
    int sum;
}t[N*30];

int build(int l,int r){
    int pos=++cnt;
    t[pos].l=l,t[pos].r=r;
    if(l==r) {t[pos].sum=a[l];return pos;}
    int mid=(l+r)>>1;
    t[pos].ls=build(l,mid);
    t[pos].rs=build(mid+1,r);
    return pos;
}

int update(int pre,int k,int x){
    int pos=++cnt;
    t[pos]=t[pre];
    if(t[pos].l==t[pos].r) {t[pos].sum=x;return pos;}
    int mid=(t[pos].l+t[pos].r)>>1;
    if(k<=mid)t[pos].ls=update(t[pre].ls,k,x);
    if(mid<k)t[pos].rs=update(t[pre].rs,k,x);
    return pos;
}

int query(int pos,int k){
    if(t[pos].l==t[pos].r){
        return t[pos].sum;
    }
    int mid=(t[pos].l+t[pos].r)>>1;
    if(k<=mid) return query(t[pos].ls,k);
    else return query(t[pos].rs,k);
}

int m;
int banben;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    root[banben]=build(1,n);
    while(m--){
        int v,op,loc,val;
        cin>>v>>op>>loc;
        banben++;
        if(op==1){
            cin>>val;
            root[banben]=update(root[v],loc,val);
        }
        else{
            root[banben]=root[v];
            cout<<query(root[v],loc)<<'\n';
        }
    }
}
/*
5 2
59 46 14 87 41
0 2 1
1 2 1
*/
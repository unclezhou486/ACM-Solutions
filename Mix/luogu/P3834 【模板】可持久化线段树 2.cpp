#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

struct segmentTree{
    int l,r,ls,rs,sum;
}t[N*20];
int cnt;
//int sum[N*20];
int a[N],b[N];
int c[N];
int build(int l,int r){
    int tr=++cnt;
    t[tr].l=l,t[tr].r=r;
    //sum[tr]=0;
    t[tr].sum=0;
    if(l==r) return tr;
    int mid=(l+r)>>1;
    t[tr].ls=build(l,mid);
    t[tr].rs=build(mid+1,r);
    return tr;
}

int update(int pre,int x){
    int tr=++cnt;
    t[tr]=t[pre];
    t[tr].sum++;
    if(t[tr].l==t[tr].r){
        return tr;
    }
    int mid=(t[tr].l+t[tr].r)>>1;
    if(x<=mid) t[tr].ls=update(t[pre].ls,x);
    if(mid<x) t[tr].rs=update(t[pre].rs,x);
    return tr;
}

int query(int pre,int tr,int k){
    if(t[tr].l==t[tr].r) return t[tr].l;
    int x=t[t[tr].ls].sum-t[t[pre].ls].sum;
    if(x>=k) return query(t[pre].ls,t[tr].ls,k);
    else return query(t[pre].rs,t[tr].rs,k-x);
}

int n,m,q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    m=unique(b+1,b+1+n)-b-1;
    c[0]=build(1,m);
    for(int i=1;i<=n;i++){
        int t=lower_bound(b+1,b+1+m,a[i])-b;
        c[i]=update(c[i-1],t);
    }
    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        cout<<b[query(c[x-1],c[y],z)]<<'\n';
    }
}
#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

struct segmentTree{
    int ls,rs,sum;
}t[N*40];
int cnt;
int n,q;
int a[N];
int la[N];
int rt[N];

int build(int l,int r){
    int tr=++cnt;
    t[tr].sum=0;
    if(l==r) return tr;
    int mid=(l+r)>>1;
    t[tr].ls=build(l,mid);
    t[tr].rs=build(mid+1,r);
    return tr;
}

int update(int pre,int l,int r,int k,int v){
    int tr=++cnt;
    t[tr]=t[pre];
    t[tr].sum+=v;
    if(l==r) return tr;
    int mid=(l+r)>>1;
    if(k<=mid) t[tr].ls=update(t[pre].ls,l,mid,k,v);
    if(mid<k) t[tr].rs=update(t[pre].rs,mid+1,r,k,v);
    return tr;    
}

int query(int tr,int l,int r,int k){
    if(l==r) return t[tr].sum;
    int mid=(l+r)>>1;
    if(k<=mid) return query(t[tr].ls,l,mid,k)+t[t[tr].rs].sum;
    if(mid<k) return query(t[tr].rs,mid+1,r,k);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    rt[0]=build(1,n);
    for(int i=1;i<=n;i++){
        if(!la[a[i]]){
            rt[i]=update(rt[i-1],1,n,i,1);
        }
        else{
            int t=update(rt[i-1],1,n,la[a[i]],-1);
            rt[i]=update(t,1,n,i,1);
        }
        la[a[i]]=i;
    }
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<query(rt[y],1,n,x)<<'\n';
    }
}
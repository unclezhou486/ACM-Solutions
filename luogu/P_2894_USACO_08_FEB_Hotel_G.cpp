#include <bits/stdc++.h>
#define pl tr<<1
#define pr tr<<1|1

using namespace std;

const int N=5e4+10;

int n,m;

struct segmentTree{
    int l,r,lmax,rmax,sum,len;
    int lz;
}t[N<<2];

void pushup(int tr){
    if(t[pl].sum==t[pl].len){
        t[tr].lmax=t[pl].len+t[pr].lmax;
    }
    else{
        t[tr].lmax=t[pl].lmax;
    }
    if(t[pr].sum==t[pr].len){
        t[tr].rmax=t[pl].rmax+t[pr].sum;
    }
    else{
        t[tr].rmax=t[pr].rmax;
    }
    t[tr].sum=max(max(t[pl].sum,t[pr].sum),(t[pl].rmax+t[pr].lmax));
}

void pushdown(int tr){
    if(t[tr].lz){
        if(t[tr].lz==1){
            t[pl].sum=t[pl].lmax=t[pl].rmax=0;
            t[pr].sum=t[pr].lmax=t[pr].rmax=0;
            t[pl].lz=t[pr].lz=1;
            t[tr].lz=0;
        }
        else{
            t[pl].sum=t[pl].lmax=t[pl].rmax=t[pl].len;
            t[pr].sum=t[pr].lmax=t[pr].rmax=t[pr].len;
            t[pl].lz=t[pr].lz=2;
            t[tr].lz=0;
        }
    }
}

void build(int l,int r,int tr){
    t[tr].l=l,t[tr].r=r;
    t[tr].lmax=t[tr].rmax=t[tr].sum=t[tr].len=(r-l+1);
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,pl);
    build(mid+1,r,pr);
}

void update(int l,int r,int tr,int k){
    if(l<=t[tr].l&&t[tr].r<=r){
        if(k==1){
            t[tr].sum=t[tr].lmax=t[tr].rmax=0;
            t[tr].lz=1;
            return;
        }
        else{
            t[tr].sum=t[tr].lmax=t[tr].rmax=t[tr].len;
            t[tr].lz=2;
            return;
        }
    }
    pushdown(tr);
    int mid=(t[tr].l+t[tr].r)>>1;
    if(l<=mid) update(l,r,pl,k);
    if(mid<r) update(l,r,pr,k);
    pushup(tr);
}

int query(int l,int r,int tr,int x){
    pushdown(tr);
    if(t[tr].l==t[tr].r) return l;
    if(t[pl].sum>=x){
        return query(l,r,pl,x);
    }
    else if(t[pl].rmax+t[pr].lmax>=x){
        int mid=(t[tr].l+t[tr].r)>>1;
        return mid-(t[pl].rmax)+1;
    }
    else{
        return query(l,r,pr,x);
    }
}

void solve(){
    cin>>n>>m;
    build(1,n,1);
    while(m--){
        int op,x;
        cin>>op>>x;
        if(op==1){
            if(t[1].sum<x) cout<<0<<'\n';
            else{
                int ans=query(1,n,1,x);
                update(ans,ans+x-1,1,1);
                cout<<ans<<'\n';
            }
        }
        else{
            int y;
            cin>>y;
            update(x,x+y-1,1,2);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
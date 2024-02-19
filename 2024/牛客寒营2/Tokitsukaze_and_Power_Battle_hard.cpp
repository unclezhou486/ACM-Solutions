#include <bits/stdc++.h>
#define pl tr<<1
#define pr tr<<1|1
#define int long long

using namespace std;

const int N=5e5+10;

int n,q;
int a[N];

struct segmentTree{
    int l,r;
    int lans,rmx,lmn,rans,all,sum,ans;
}t[N<<2];

segmentTree merge(segmentTree x,segmentTree y){
    segmentTree res;
    res.l=x.l,res.r=y.r;
    res.sum=x.sum+y.sum;
    res.rmx=max(x.rmx+y.sum,y.rmx);
    res.lmn=min(x.lmn,x.sum+y.lmn);
    res.lans=max({x.lans,x.all-y.lmn,x.sum-y.lmn,x.sum+y.lans});
    res.rans=max({y.rans,x.rmx+y.all,x.rmx-y.sum,x.rans-y.sum});
    res.all=max({x.all-y.sum,x.sum-y.sum,x.sum+y.all});
    res.ans=max({x.ans,y.ans,x.rmx-y.lmn,x.rans-y.lmn,x.rmx+y.lans});
    return res;
}

void pushup(int tr){
    t[tr]=merge(t[pl],t[pr]);
}

void build(int l,int r,int tr){
    t[tr].l=l,t[tr].r=r;
    //cout<<t[tr].l<<' '<<t[tr].r<<' '<<tr<<'\n';
    t[tr].rmx=t[tr].lans=t[tr].rans=t[tr].all=t[tr].ans=-1e18;
    t[tr].lmn=1e18;t[tr].sum=0;
    if(l==r){
        t[tr].sum=t[tr].rmx=t[tr].lmn=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,pl);
    build(mid+1,r,pr);
    pushup(tr);
}

void update(int l,int r,int tr,int k){
    if(l<=t[tr].l&&t[tr].r<=r){
        t[tr].lmn=t[tr].sum=t[tr].rmx=k;
        return;
    }
    int mid=(t[tr].l+t[tr].r)>>1;
    if(l<=mid) update(l,r,pl,k);
    if(mid<r) update(l,r,pr,k);
    pushup(tr);
}

segmentTree query(int l,int r,int tr){
    //cout<<l<<' '<<r<<' '<<t[tr].l<<' '<<t[tr].r<<' '<<tr<<'\n';
    if(l<=t[tr].l&&t[tr].r<=r){
        return t[tr];
    }
    int mid=(t[tr].l+t[tr].r)>>1;
    if(mid>=r) return query(l,r,pl);
    if(l>mid) return query(l,r,pr);
    return merge(query(l,r,pl),query(l,r,pr));
}

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,n,1);
    //cout<<"ccf "<<t[1].l<<' '<<t[1].r<<' '<<1<<'\n';
    while(q--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            update(x,x,1,y);
        }
        else{
            cout<<query(x,y,1).ans<<'\n';
        }
    }
}

signed main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0),cout.tie(0);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
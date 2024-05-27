// 主席树加整体二分
#include <bits/stdc++.h>

using namespace std;

const int N=3e5+10;

int n,a[N];

struct BIT {
    int n;
    int b[N];
    void clear(int x) {
        n=x;
    }
    int lowbit(int x) {
        return x&(-x);
    }
    void add(int k,int x){
        for(;k<=n;k+=lowbit(k)) b[k]+=x;
    }
    int query(int x){
        int res=0;
        for(;x;x-=lowbit(x)) res+=b[x];
        return res;
    }
}bit;

int root[N];

struct SegmentTree{
    struct Node{
        int ls,rs,sum;
    }t[N*20];
    int tot,n;
    void clear(int x){
        tot=0;
        n=x;
    }
    void insert(int &tr,int pre,int l,int r,int v){
        tr=++tot;
        t[tr].sum=t[pre].sum+1;
        if(l==r) return ;
        int mid=(l+r)>>1;
        if(v<=mid) insert(t[tr].ls,t[pre].ls,l,mid,v),t[tr].rs=t[pre].rs;
        else insert(t[tr].rs,t[pre].rs,mid+1,r,v),t[tr].ls=t[pre].ls;
    }
    void insert(int &tr,int pre,int v){
        insert(tr,pre,1,n,v);
    }
    int query(int tr,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr) return t[tr].sum;
        int mid=(l+r)>>1;
        int ans=0;
        if(ql<=mid) ans+=query(t[tr].ls,l,mid,ql,qr);
        if(mid<qr) ans+=query(t[tr].rs,mid+1,r,ql,qr);
        return ans;
    }
    int query(int tr,int ql,int qr){
        return query(tr,1,n,ql,qr);
    }
}seg;

int sl[N],cntl,sr[N],cntr;

int res[N];

int query(int x,int y){
    x=sl[x],y=sr[y];
    if(y<x||a[x]<a[y]) return 0;
    int rx=root[x],ry=root[y-1];
    return seg.query(ry,a[y]+1,a[x]-1)-seg.query(rx,a[y]+1,a[x]-1);
}

void sol(int l,int r,int ql,int qr){
    if(ql>qr) return;
    int mid=(ql+qr)>>1;
    int id=0;
    for(int i=r,tmp;i>=l;i--){
        if((tmp=query(i,mid))>res[mid]){
            res[mid]=tmp;
            id=i;
        }
    }
    sol(l,id,ql,mid-1);
    sol(id,r,mid+1,qr);
}

void solve(){
    cin>>n;
    bit.clear(n),seg.clear(n);
    for(int i=1;i<=n;i++) cin>>a[i];
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=bit.query(n)-bit.query(a[i]);
        bit.add(a[i],1);
    }
    for(int i=1;i<=n;i++){
        seg.insert(root[i],root[i-1],a[i]);
    }
    cntl=cntr=0;
    for(int i=1;i<=n;i++){
        if(!cntl||a[sl[cntl]]<a[i]) sl[++cntl]=i;
    }
    for(int i=n;i;i--){
        if(!cntr||a[sr[cntr]]>a[i]) sr[++cntr]=i;
    }
    sol(1,cntl,1,cntr);
    int tmp=0;
    for(int i=1;i<=cntr;i++){
        tmp=max(tmp,res[i]);
    }
    ans-=2*tmp;
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
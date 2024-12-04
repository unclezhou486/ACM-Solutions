#include <bits/stdc++.h>

using namespace std;

constexpr int N=2e5+10;
constexpr int _l=1;
constexpr int _r=2e5;

int root[N];
int idx=1;

struct node{
    int l,r;
    long long num;
}tr[N<<5];
int tot;

void update(int &rt,int x,long long k,int l=_l,int r=_r){
    if(!rt) rt=++tot;
    tr[rt].num+=k;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(x<=mid) update(tr[rt].l,x,k,l,mid);
    if(mid<x) update(tr[rt].r,x,k,mid+1,r);
    return;
}

long long query(int rt,int x,int y,int l=_l,int r=_r){
    if(!rt) return 0;
    if(x<=l&&r<=y){
        return tr[rt].num;
    }
    int mid=(l+r)>>1;
    long long res=0;
    if(x<=mid) res+=query(tr[rt].l,x,y,l,mid);
    if(mid<y) res+=query(tr[rt].r,x,y,mid+1,r);
    return res;
}

int kth(int rt,int k,int l=_l,int r=_r){
    // if(!rt) return ;
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(tr[tr[rt].l].num>=k) return kth(tr[rt].l,k,l,mid);
    else return kth(tr[rt].r,k-tr[tr[rt].l].num,mid+1,r);
}


int merge(int x,int y){
    if(!x||!y){
        return x+y;
    }
    tr[x].num+=tr[y].num;
    tr[x].l=merge(tr[x].l,tr[y].l);
    tr[x].r=merge(tr[x].r,tr[y].r);
    return x;
}

void split(int x,int &y,long long k) {
    if(!x) return;
    if(!y) y=++tot;
    long long res=tr[tr[x].l].num;
    if(k>res){
        split(tr[x].r,tr[y].r,k-res);
    }
    else{
        swap(tr[x].r,tr[y].r);
    }
    if(k<res){
        split(tr[x].l,tr[y].l,k);
    }
    tr[y].num=tr[x].num-k;
    tr[x].num=k;
    return;
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        update(root[1],i,x);
    }
    for(int i=1;i<=m;i++){
        long long op,p,x,y;
        cin>>op>>p;
        if(op==0){
            cin>>x>>y;
            long long res1=query(root[p],1,y),res2=query(root[p],x,y);
            int res=0;
            split(root[p],root[++idx],res1-res2);
            split(root[idx],res,res2);
            root[p]=merge(root[p],res);
        }
        else if(op==1){
            cin>>x;
            merge(root[p],root[x]);
        }
        else if(op==2){
            cin>>x>>y;
            update(root[p],y,x);
        }
        else if(op==3){
            cin>>x>>y;
            cout<<query(root[p],x,y)<<'\n';
        }
        else{
            cin>>x;
            if(tr[root[p]].num<x) cout<<-1<<'\n';
            else cout<<kth(root[p],x)<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
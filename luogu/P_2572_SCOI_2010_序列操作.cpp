#include <bits/stdc++.h>
#define pl tr<<1
#define pr tr<<1|1

using namespace std;

const int N=1e5+10;

struct segmentTree{
    int l,r,lm0,lm1,rm1,rm0,sm0,sm1,sum,len;
    int lz1,lz2;
}t[N<<2];

void pushup(int tr){
    if(t[pl].lm1==t[pl].len){
        t[tr].lm1=t[pl].lm1+t[pr].lm1;
    }
    else{
        t[tr].lm1=t[pl].lm1;
    }
    if(t[pr].rm1==t[pr].len){
        t[tr].rm1=t[pr].rm1+t[pl].rm1;
    }
    else{
        t[tr].rm1=t[pr].rm1;
    }
    if(t[pl].lm0==t[pl].len){
        t[tr].lm0=t[pl].lm0+t[pr].lm0;
    }
    else{
        t[tr].lm0=t[pl].lm0;
    }
    if(t[pr].rm0==t[pr].len){
        t[tr].rm0=t[pr].rm0+t[pl].rm0;
    }
    else{
        t[tr].rm0=t[pr].rm0;
    }
    t[tr].sm1=max(max(t[pl].sm1,t[pr].sm1),t[pl].rm1+t[pr].lm1);
    t[tr].sm0=max(max(t[pl].sm0,t[pr].sm0),t[pl].rm0+t[pr].lm0);
    t[tr].sum=t[pl].sum+t[pr].sum;
}

void pushdown(int tr){
    if(t[tr].lz1){
        if(t[tr].lz1==1){//1
            t[pl].lm0=t[pl].rm0=t[pl].sm0=0;
            t[pl].lm1=t[pl].rm1=t[pl].sm1=t[pl].len;
            t[pl].sum=t[pl].len;
            t[pr].lm0=t[pr].rm0=t[pr].sm0=0;
            t[pr].lm1=t[pr].rm1=t[pr].sm1=t[pr].len;
            t[pr].sum=t[pr].len;
            t[pl].lz1=1;
            t[pr].lz1=1;
            t[pl].lz2=t[pr].lz2=0;
            t[tr].lz1=0;
        }
        else{
            t[pl].lm0=t[pl].rm0=t[pl].sm0=t[pl].len;
            t[pl].lm1=t[pl].rm1=t[pl].sm1=t[pl].sum=0;
            t[pr].lm0=t[pr].rm0=t[pr].sm0=t[pr].len;
            t[pr].lm1=t[pr].rm1=t[pr].sm1=t[pr].sum=0;
            t[pl].lz1=2;
            t[pr].lz1=2;
            t[pl].lz2=t[pr].lz2=0;
            t[tr].lz1=0;
        }
    }
    if(t[tr].lz2){
        swap(t[pl].lm0,t[pl].lm1);
        swap(t[pl].rm0,t[pl].rm1);
        swap(t[pl].sm0,t[pl].sm1);
        t[pl].sum=(t[pl].len-t[pl].sum);
        swap(t[pr].lm0,t[pr].lm1);
        swap(t[pr].rm0,t[pr].rm1);
        swap(t[pr].sm0,t[pr].sm1);
        t[pr].sum=(t[pr].len-t[pr].sum);
        if(t[pl].lz1==1) t[pl].lz1=2;
        else if(t[pl].lz1==2) t[pl].lz1=1;
        else t[pl].lz2^=t[tr].lz2;
        if(t[pr].lz1==1) t[pr].lz1=2;
        else if(t[pr].lz1==2) t[pr].lz1=1;
        else t[pr].lz2^=t[tr].lz2;
        t[tr].lz2=0;
    }
}

void build(int l,int r,int tr){
    t[tr].l=l,t[tr].r=r;
    t[tr].lm0=t[tr].rm0=t[tr].sm0=t[tr].len=(r-l+1);
    t[tr].lm1=t[tr].rm1=t[tr].sm1=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,pl);
    build(mid+1,r,pr);
}

void update(int l,int r,int tr,int k){
    if(l<=t[tr].l&&t[tr].r<=r){
        if(k==0){
            t[tr].lm0=t[tr].rm0=t[tr].sm0=t[tr].len;
            t[tr].lm1=t[tr].rm1=t[tr].sm1=t[tr].sum=0;
            t[tr].lz1=2;
            t[tr].lz2=0;
        }
        else if(k==1){
            t[tr].lm0=t[tr].rm0=t[tr].sm0=0;
            t[tr].lm1=t[tr].rm1=t[tr].sm1=t[tr].sum=t[tr].len;
            t[tr].lz1=1;
            t[tr].lz2=0;
        }
        else if(k==2){
            swap(t[tr].lm0,t[tr].lm1);
            swap(t[tr].rm0,t[tr].rm1);
            swap(t[tr].sm0,t[tr].sm1);
            t[tr].sum=(t[tr].len-t[tr].sum);
            t[tr].lz2^=1;
        }
        return;
    }
    pushdown(tr);
    int mid=(t[tr].l+t[tr].r)>>1;
    if(l<=mid) update(l,r,pl,k);
    if(mid<r) update(l,r,pr,k);
    pushup(tr);
}

int query1(int l,int r,int tr){
    if(l<=t[tr].l&&t[tr].r<=r){
        return t[tr].sum;
    }
    pushdown(tr);
    int mid=(t[tr].l+t[tr].r)>>1;
    int ans=0;
    if(l<=mid)ans+=query1(l,r,pl);
    if(mid<r) ans+=query1(l,r,pr); 
    return ans;
}

int query2(int l,int r,int tr){
    if(l<=t[tr].l&&t[tr].r<=r){return t[tr].sm1;}
    pushdown(tr);
    int mid=(t[tr].l+t[tr].r)>>1;
    if(r<=mid) return query2(l,r,pl);
    else if(l>mid) return query2(l,r,pr);
    else return max(max(query2(l,r,pl),query2(l,r,pr)),min(t[pr].lm1,r-mid)+min(t[pl].rm1,mid-l+1));
}

int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    build(1,n,1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        update(i,i,1,x);
    }
    while(m--){
        int op,l,r;
        cin>>op>>l>>r;
        l++,r++;
        if(op<3){
            update(l,r,1,op);
        }
        else{
            if(op==3){
                cout<<query1(l,r,1)<<'\n';
            }
            else{
                cout<<query2(l,r,1)<<'\n';
            }
        }
    }
}
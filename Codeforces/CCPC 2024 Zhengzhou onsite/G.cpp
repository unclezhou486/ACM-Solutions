#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int N=2e5+10;
constexpr int M=2;

int n;
long long a[N];

long long x[M],mod[M];

struct node{
    long long b[M];
    node operator+(const node a){
        node c;
        for(int i=0;i<M;i++){
            c.b[i]=(b[i]+a.b[i])%mod[i];
        }
        return c;
    }
    node operator+(const long long x){
        node c;
        for(int i=0;i<M;i++){
            c.b[i]=(b[i]+x)%mod[i];
        }
        return c;
    }
    node operator*(const node a){
        node c;
        for(int i=0;i<M;i++){
            c.b[i]=(b[i]*a.b[i])%mod[i];
        }
        return c;
    }
    node operator*(const long long x){
        node c;
        for(int i=0;i<M;i++){
            c.b[i]=(b[i]*x)%mod[i];
        }
        return c;
    }
    void operator=(int x){
        // node c;
        for(int i=0;i<M;i++){
            b[i]=x;
        }
        return;
    }
    bool operator==(const node a){
        bool flag=true;
        for(int i=0;i<M;i++){
            flag&=(b[i]==a.b[i]);
        }
        return flag;
    }
};

node mi,nimi;

long long qmi(long long a,long long b,long long mod){
    a%=mod;
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

struct SegmentTree{
    node sum[N<<2];
    node lz[N<<2];
    void pushup(int tr){
        sum[tr]=sum[tr<<1]+sum[tr<<1|1];
    }

    void pushdown(int tr){
        sum[tr<<1]=sum[tr<<1]*lz[tr];
        sum[tr<<1|1]=sum[tr<<1|1]*lz[tr];
        lz[tr<<1]=lz[tr<<1]*lz[tr];
        lz[tr<<1|1]=lz[tr<<1|1]*lz[tr];
        lz[tr]=1;
    }

    void build(int l=1,int r=n,int tr=1){
        lz[tr]=1;
        if(l==r){
            for(int i=0;i<M;i++){
                if(a[l]<0){
                    long long res=qmi(x[i],abs(a[l]),mod[i]);
                    res=qmi(res,mod[i]-2,mod[i]);
                    sum[tr].b[i]=res;
                }
                else{
                    sum[tr].b[i]=qmi(x[i],a[l],mod[i]);
                }
            }
            return;
        }   
        int mid=(l+r)>>1;
        build(l,mid,tr<<1);
        build(mid+1,r,tr<<1|1);
        pushup(tr);
    }


    void update(int l,int r,node& k,int X=1,int Y=n,int tr=1){
        if(l<=X&&Y<=r){
            sum[tr]=sum[tr]*k;
            lz[tr]=lz[tr]*k;
            return;
        }
        pushdown(tr);
        int mid=(X+Y)>>1;
        if(l<=mid) update(l,r,k,X,mid,tr<<1);
        if(mid<r) update(l,r,k,mid+1,Y,tr<<1|1);
        pushup(tr);
        return;
    }

    node query(int l,int r,int X=1,int Y=n,int tr=1){
        if(l<=X&&Y<=r){
            return sum[tr]; 
        }
        pushdown(tr);
        int mid=(X+Y)>>1;
        node c;
        for(int i=0;i<M;i++) c.b[i]=0;
        if(l<=mid) c=c+query(l,r,X,mid,tr<<1);
        if(mid<r) c=c+query(l,r,mid+1,Y,tr<<1|1);
        return c;
    }

}t1,t2;

struct Node{
    long long sum[N<<2];
    long long lz[N<<2];
    void pushup(int tr){
        sum[tr]=sum[tr<<1]+sum[tr<<1|1];
    }
    void pushdown(int tr,int l,int r){
        if(!lz[tr]) return;
        int mid=(l+r)>>1;
        sum[tr<<1]=sum[tr<<1]+lz[tr]*(mid-l+1);
        sum[tr<<1|1]=sum[tr<<1|1]+lz[tr]*(r-mid);
        lz[tr<<1]=lz[tr<<1]+lz[tr];
        lz[tr<<1|1]=lz[tr<<1|1]+lz[tr];
        lz[tr]=0;
    }

    void build(int l=1,int r=n,int tr=1){
        lz[tr]=0;
        sum[tr]=0;
        if(l==r){
            sum[tr]=a[l];
            return;
        }   
        int mid=(l+r)>>1;
        build(l,mid,tr<<1);
        build(mid+1,r,tr<<1|1);
        pushup(tr);
    }


    void update(int l,int r,long long k,int X=1,int Y=n,int tr=1){
        if(l<=X&&Y<=r){
            sum[tr]+=(Y-X+1)*k;
            lz[tr]+=k;
            return;
        }
        pushdown(tr,X,Y);
        int mid=(X+Y)>>1;
        if(l<=mid) update(l,r,k,X,mid,tr<<1);
        if(mid<r) update(l,r,k,mid+1,Y,tr<<1|1);
        pushup(tr);
        return;
    }

    long long query(int l,int r,int X=1,int Y=n,int tr=1){
        if(l<=X&&Y<=r){
            return sum[tr]; 
        }
        pushdown(tr,X,Y);
        int mid=(X+Y)>>1;
        long long c=0;
        if(l<=mid) c=c+query(l,r,X,mid,tr<<1);
        if(mid<r) c=c+query(l,r,mid+1,Y,tr<<1|1);
        return c;
    }
}t3;

void solve(){
    // int n;
    mt19937 myrand(clock());
    mod[0]=1e9+7;
    mod[1]=998244353;
    // x[0]=4125202024;
    // x[1]=4263002122;
    for(int i=0;i<M;i++){
        x[i]=myrand();
        // mod[i]=myrand();
        // cout<<x[i]<<" \n"[i==M-1];
    }
    int q;
    cin>>n>>q;
    // vector<int> a(n+10);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    t3.build();
    t1.build();
    for(int i=1;i<=n;i++){
        a[i]=-a[i];
    }
    t2.build();
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r,xx;
            cin>>l>>r>>xx;
            for(int i=0;i<M;i++){
                mi.b[i]=qmi(x[i],xx,mod[i]);
                nimi.b[i]=qmi(mi.b[i],mod[i]-2,mod[i]);
            }
            t1.update(l,r,mi);
            t2.update(l,r,nimi);
            t3.update(l,r,xx);
        }
        else{
            int l,r;
            cin>>l>>r;
            node res1=t1.query(l,r);
            node res2=t2.query(l,r);
            int m=(r-l+1)/2;
            long long res3=t3.query(l,r);
            res3/=m;
            for(int i=0;i<M;i++){
                res2.b[i]=(res2.b[i]*qmi(x[i],res3,mod[i]))%mod[i];
            }
            bool flag=(res1==res2);
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
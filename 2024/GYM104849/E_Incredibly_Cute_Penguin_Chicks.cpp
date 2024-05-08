//  属于是完完全全是临摹的ov_vo的代码了

#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

const int mod=998244353;

int n,m;
int dp,sum[3];

struct node{
    int l,r,sum;
};

struct segmentTree{
    map<int,int> a;
    int tot;
    node tr[N*22];
    void update(int x,int y,int &rt ,int l,int r){
        if(!rt) rt=++tot;
        tr[rt].sum=(1ll*tr[rt].sum+y)%mod;
        if(l==r) return;
        int mid=(l+r)>>1;
        if(x<=mid) update(x,y,tr[rt].l,l,mid);
        else update(x,y,tr[rt].r,mid+1,r);
    }
    void add(int k,int x,int y){
        update(x,y,a[k],-n,n);
    }
    int query(int x,int y,int rt,int l,int r){
        if(x<=l&&l<=y) return tr[rt].sum;
        if(!rt) return 0;
        int mid=(l+r)>>1;
        long long ans=0;
        if(x<=mid) ans+=query(x,y,tr[rt].l,l,mid);
        if(mid<y) ans+=query(x,y,tr[rt].r,mid+1,r);
        return ans%mod;
    }
    int find(int x,int y){
        return query(y+1,n,a[x],-n,n);
    }
}t[3];

void add(){
    t[0].add(sum[2]-sum[1],sum[1]-sum[0],dp);
    t[1].add(sum[2]-sum[0],sum[0]-sum[1],dp);
    t[2].add(sum[1]-sum[0],sum[0]-sum[2],dp);
}

int find(){
    long long ans=0;
    ans+=t[0].find(sum[2]-sum[1],sum[1]-sum[0]);
    ans+=t[1].find(sum[2]-sum[0],sum[0]-sum[1]);
    ans+=t[2].find(sum[1]-sum[0],sum[0]-sum[2]);
    return ans%mod;
}

void solve(){
    string s;
    cin>>s;
    n=s.size();
    s=' '+s;
    dp=1;
    add();
    for(int i=1;i<=n;i++){
        if(s[i]=='I') sum[0]++;
        else if(s[i]=='C') sum[1]++;
        else sum[2]++;
        dp=find();
        add();
    }
    cout<<dp<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;

}
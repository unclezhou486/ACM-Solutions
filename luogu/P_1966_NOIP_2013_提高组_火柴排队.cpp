#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int mod=1e8-3;
int n;

struct node{
    int x,id;
}a[N],b[N];
int c[N];
int d[N];

bool cmp(node a,node b){
    return a.x<b.x;
}

int lowbit(int x){return x&(-x);}

void add(int k,int x){for(;k<=n;k+=lowbit(k))d[k]+=x;}

int query(int x){
    int res=0;
    for(;x;x-=lowbit(x)){
        res+=d[x];
    }
    return res;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].id=i;
    }
    for(int i=1;i<=n;i++) cin>>b[i].x,b[i].id=i;
    sort(a+1,a+1+n,cmp);sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++){
        c[b[i].id]=a[i].id;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=query(n)-query(c[i]);
        ans%=mod;
        add(c[i],1);
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
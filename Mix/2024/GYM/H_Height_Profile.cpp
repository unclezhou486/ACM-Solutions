#include <bits/stdc++.h>

#define LD long double
 
using namespace std;

const int N=1e5+10;

int n,k;

LD h[N];
LD maxn=0;

struct node{
    LD hight;
    int idx;
}a[N];

bool cmp(node a,node b){
    if(a.hight==b.hight) return a.idx<b.idx;
    return a.hight<b.hight;
}

LD hi[N];

void solve(){
    LD g,ans;
    ans=-1;
    cin>>g;
    g=g*10;
    //cout<<maxn<<' '<<g<<'\n';
    if(maxn<g){
        cout<<-1<<'\n';
        return;
    }
    for(int i=0;i<=n;i++){
        a[i]={h[i]-g*i,i};
        hi[i]=a[i].hight;
    }
    sort(a,a+1+n,cmp);
    int l=a[0].idx;
    for(int i=1;i<=n;i++){
        int r=a[i].idx;
        if(l<r){
            LD res=0;
            if(l>0)res=max(res,(hi[r]-hi[l])/fabs(hi[l]-hi[l-1]));
            if(r<n)res=max(res,(hi[r]-hi[l])/fabs(hi[r+1]-hi[r]));
            if(res>1.0) res=1.0;
            //cout<<hi[l]<<' '<<hi[r]<<' ';
            //cout<<l<<' '<<r<<' '<<res<<'\n';
            ans=max(ans,r-l+res);
        }
        l=min(l,r);
    }
    cout<<fixed<<setprecision(12)<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        maxn=max(maxn,h[i]-h[i-1]);
    }
    while(k--){
        solve();
    }
}
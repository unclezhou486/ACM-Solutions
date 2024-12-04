#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;

const int N=1e5+10;

int a[N],prer[N];
int val[N];
struct node{
    int w,l,r;
}b[N];

bool cmp(node a,node b){
    return a.w>b.w;
}

void solve(){
    cin>>n>>m;
    int suml=0,sumr=0;
    int sumval=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>b[i].w>>b[i].l>>b[i].r;
        suml+=b[i].l;
        sumr+=b[i].r;
        sumval+=b[i].l*b[i].w;
    }
    for(int i=1;i<=n;i++){
        int res=sumval-b[i].l*b[i].w;
        res+=(m-(suml-b[i].l))*b[i].w;
        ans=max(ans,res);
    }
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++){
        prer[i]=prer[i-1]+(b[i].r-b[i].l);
        val[i]=val[i-1]+(b[i].r-b[i].l)*b[i].w;
    }
    for(int i=1;i<=n;i++){
        int res=sumval-b[i].l*b[i].w;
        b[1+n].w=b[i].w;
        int mm=m-(suml-b[i].l);
        auto it=upper_bound(prer+1,prer+1+n,mm)-(prer);
        if(it>=i){
            res+=val[i-1];
            res+=b[i].w*(mm-prer[i-1]);
        }
        else{
            res+=val[it-1];
            res+=b[it].w*(mm-prer[it-1]);
        }
        ans=max(ans,res);
    }
    cout<<ans<<'\n';
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
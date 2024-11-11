#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

struct node{
    int x,y;
}a[N];

bool cmp(node a,node b){
    return a.x<b.x;
}

void solve(){
    int n,m;
    int ans;
    cin>>n>>m;
    ans=m;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n,cmp);
    int res1=0,res2;
    for(int i=1;i<=n;i++){
        res1+=a[i].y;
        res2=a[i].x;
        if(m>=res2-res1){
            ans=max(ans,m+res1);
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
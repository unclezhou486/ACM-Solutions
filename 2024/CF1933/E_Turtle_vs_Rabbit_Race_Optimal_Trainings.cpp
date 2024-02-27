#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int n,a[N];
int s[N];
int q;
int ll,u;

int jisuan(int rr){
    return (2*u+1-(s[rr]-s[ll-1]))*(s[rr]-s[ll-1])/2;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    cin>>q;
    while(q--){
        cin>>ll>>u;
        int l=ll,r=n;
        while(r-l>10){
            int mid1=(l+(r-l)/3);
            int mid2=(r-(r-l)/3);
            if(jisuan(mid1)<jisuan(mid2)){
                l=mid1;
            }
            else r=mid2;
        }
        int maxn=-1e9;
        int ans;
        for(int i=r;i>=l;i--){
            int res=(2*u+1-(s[i]-s[ll-1]))*(s[i]-s[ll-1])/2;
            if(res>maxn){
                maxn=res;
                ans=i;
            }
            else if(res==maxn){
                ans=i;
            }
        }
        cout<<ans<<' ';
    }
    cout<<'\n';
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
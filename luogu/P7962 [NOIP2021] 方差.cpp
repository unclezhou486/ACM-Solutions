#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e6+10;

int n;

int a[N],b[N];
int f[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int maxn=0;
    for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
    for(int i=2;i<=n;i++) b[i-1]=a[i]-a[i-1];
    for(int i=1;i<=maxn*n;i++) f[i]=1e18;
    sort(b+1,b+n);
    
    int maxx=maxn*(n-1);
    int res=0;
    for(int i=1;i<n;i++){
        res+=b[i];
        if(!b[i]) continue;
        //cout<<res<<' '<<b[i]<<'\n';
        for(int j=maxx;j>=0;j--){
            if(f[j]==1e18) continue;
            if(j+res<=maxx)f[j+res]=min(f[j]+res*res,f[j+res]);
            if(j+i*b[i]<=maxx)f[j+i*b[i]]=min(f[j+i*b[i]],f[j]+2*b[i]*j+b[i]*b[i]*i);
            f[j]=1e18;
            //if(f[j]!=1e18) cout<<f[j]<<'\n';
        }
    }
    int ans=1e18;
    for(int i=0;i<=maxx;i++){
        if(f[i]==1e18) continue;
        //cout<<n*f[i]<<' '<<i*i<<'\n';
        ans=min(ans,n*f[i]-i*i);
    }
    cout<<ans<<'\n';
}
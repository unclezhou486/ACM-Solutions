#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;

int n,m,k,idx;

int a[N],b[N],c[N];

int check(int x){
    return max(abs(x-a[idx]),abs(x-a[idx+1]));
}

void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //if(i>2) ;
    }
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=k;i++) cin>>c[i];
    sort(b+1,b+1+m);
    //cout<<b[1]<<'\n';
    sort(c+1,c+1+k);
    int maxn1=0,maxn2=0;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]>maxn1){
            maxn2=maxn1;
            maxn1=a[i]-a[i-1];
            idx=i-1;
        }
        else{
            if(a[i]-a[i-1]>=maxn2){
                maxn2=a[i]-a[i-1];
            }
        }
    }
    if(maxn2==maxn1){
        cout<<maxn2<<'\n';
        return;
    }
    int minn=maxn1;
    for(int i=1;i<=m;i++){
        int l=1,r=k;
        while(r-l>=10){
            int mid1=l+(r-l)/3;
            int mid2=r-(r-l)/3;
            if(check(b[i]+c[mid1])>check(b[i]+c[mid2])){
                l=mid1;
            }
            else{
                r=mid2;
            }
        }
        int maxn=1e18;
        for(int j=l;j<=r;j++){
            //cout<<i<<' '<<j<<' '<<check(b[i]+c[j])<<'\n';
            maxn=min(maxn,check(b[i]+c[j]));
        }
        minn=min(minn,maxn);
    }
    cout<<max(minn,maxn2)<<'\n';
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
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int n,a,r,m;

int b[N];
int s[N];

int check(int x){
    int pos=lower_bound(b+1,b+1+n,x)-(b+1);
    int res=0;
    int k1=x*pos-s[pos];
    int k2=s[n]-s[pos]-x*(n-pos);
    res=min(k1,k2);
    k1-=res,k2-=res;
    int ress=0;
    ress+=res*m;
    ress+=k1*a;
    ress+=k2*r;
    return ress;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>a>>r>>m;
    m=min(m,a+r);
    int l=1e9,r=0;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+b[i];
    int ans=check(s[n]/n);
    ans=min(ans,check(s[n]/n+1));
    for(int i=1;i<=n;i++){
        ans=min(ans,check(b[i]));
    }
    cout<<ans<<'\n';
}
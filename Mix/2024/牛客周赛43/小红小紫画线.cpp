#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;

long long qmi(long long a,long long b){
    a%=mod;
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

long long inv(long long x){
    return qmi(x,mod-2);
}

long long C(long long n,long long m){
    if(n<m) return 0;
    long long res=1;
    //if(m>n-m) m=n-m;
    for(int i=n-m+1;i<=n;i++){
        res*=(i%mod);res%=mod;
    }
    for(int i=1;i<=m;i++){
        res*=inv(i);res%=mod;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<long long > a(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    long long ans=0;
    long long res=0;
    res=2*C(sum,4)%mod;
    ans+=res,ans%=mod;
    for(int i=0;i<n;i++){
        res=2*C(a[i],3)*((sum-a[i])%mod)%mod;
        ans-=res;ans%=mod;
    }
    for(int i=0;i<n;i++){
        res=2*C(a[i],4)%mod;
        ans-=res;ans%=mod;
    }
    for(int i=0;i<n;i++){
        res=2*C(sum-a[i],2)*a[i]%mod;
        ans+=res;
        ans%=mod;
    }
    ans+=mod;
    ans%=mod;
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
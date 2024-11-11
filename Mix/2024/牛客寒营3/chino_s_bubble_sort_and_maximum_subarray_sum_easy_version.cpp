#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

long long n,a[N],k;
long long s[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    long long ans=-1e18;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            ans=max(ans,s[i]-s[j]);
            if(i+1<=n&&k) ans=max(ans,s[i+1]-a[i]-s[j]);
            if(j&&k)ans=max(ans,s[i]-s[j+1]+a[j]);
        }
    }
    cout<<ans<<'\n';
}
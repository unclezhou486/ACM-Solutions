#include <bits/stdc++.h>

using namespace std;

const int N=110;

int n,a[N];

void solve(){
    cin>>n;
    int ans=-1e9;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int i=1,j=n,k=2,l=n-1;
    ans=abs(a[i]-a[j])+abs(a[j]-a[k])+abs(a[k]-a[l])+abs(a[l]-a[i]);
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,a[N];

void solve(){
    int x,n,y;
    cin>>x>>n>>y;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[n+1]=a[1]+x;
    int ans=n-2;
    bool fl=0;
    for(int i=2;i<=n+1;i++){
        if(a[i]-a[i-1]==2) ans++;
    }
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
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+5),b(n+5),pre(n+5),suf(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++) b[i]=gcd(a[i],a[i+1]);
    b[n]=1e9;
    pre[0]=1,suf[n]=1;
    for(int i=1;i<n;i++){
        if(pre[i-1]&&b[i]>=b[i-1]) pre[i]=1;
    }
    for(int i=n-1;i>=1;i--){
        if(suf[i+1]&&b[i]<=b[i+1]) suf[i]=1;
    }
    for(int i=2;i<n;i++){
        if(pre[i-2]&&suf[i+1]){
            int d=gcd(a[i-1],a[i+1]);
            //cout<<"CCF:"<<i<<' '<<d<<' '<<b[i-2]<<' '<<b[i+1]<<'\n';
            if(b[i-2]<=d&&d<=b[i+1]){
                cout<<"YES\n";
                return;
            }
        }
    }
    if(pre[n-2]||suf[2]){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
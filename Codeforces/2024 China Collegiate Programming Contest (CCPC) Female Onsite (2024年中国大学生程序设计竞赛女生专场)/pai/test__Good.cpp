#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    long long k;
    cin>>n>>k;
    vector<long long> a(n+10),b(n+10);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=0;
    for(int i=0;i<=k;i++){
        for(int j=1;j<=n;j++){
            b[j]=a[j]^i;
        }
        bool flag=true;
        for(int j=2;j<=n;j++){
            if(b[j]<b[j-1]){
                flag=false;
            }
        } 
        if(flag) ans+=1;
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
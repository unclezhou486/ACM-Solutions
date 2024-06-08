#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<long long> b(n+1);
    auto check = [&](long long x) -> bool {
        long long res=0;
        for(int i=1;i<=n;i++){
            b[i]=x/a[i];
            if(!b[i]) b[i]=1;
            if(b[i]>1e9) b[i]=1e9;
            res+=b[i];
            
        }
        for(int i=1;i<=n;i++){
            if(res>=a[i]*b[i]) return 0;
        }
        if(res>x) return 0;
        else return 1;
    };
    long long l=n,r=1e11;
    while(l<r){
        long long mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    if(check(l)){
        for(int i=1;i<=n;i++){
            cout<<b[i]<<" \n"[i==n];
        }
    }
    else{
        cout<<"-1\n";
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
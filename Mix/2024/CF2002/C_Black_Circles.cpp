#include <bits/stdc++.h>
#define int long long
using namespace std;

long long dis(long long x,long long y,long long xx,long long yy){
    return (x-xx)*(x-xx)+(y-yy)*(y-yy);
}

void solve(){
    int n;
    cin>>n;
    vector<int> x(n+1),y(n+1);
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    int xs,ys,xt,yt;
    cin>>xs>>ys>>xt>>yt;
    long long res=dis(xs,ys,xt,yt);
    for(int i=1;i<=n;i++){
        long long ress=dis(x[i],y[i],xt,yt);
        if(ress<=res){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
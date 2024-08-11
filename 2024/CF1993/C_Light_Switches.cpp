#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+10);
    set<int> se;
    int minn=2*k;
    int maxn=0;
    int res=0;
    for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]),res=max(res,a[i]/(2*k)),minn=min(minn,a[i]%(2*k)),se.insert(a[i]%(2*k));
    //cout<<minn<<" "<<maxn<<'\n';
    for(auto x:se){
        int y=(x+k-1)%(2*k);
        if(x<=k){
            if(*se.upper_bound(-1)==x&&se.upper_bound(y)==se.end()){
                auto it=se.upper_bound(y);
                it--;
                int ans=*it+2*k*res;
                while(ans<maxn) ans+=2*k;
                cout<<ans<<'\n';
                return;
            }
        }
        else{
            if(*se.upper_bound(y)==x){
                auto it=se.lower_bound(x);
                if(it==se.begin()){
                    auto itt=se.end();
                    itt--;
                    int ans=*itt+2*k*res;
                    while(ans<maxn) ans+=2*k;
                    cout<<ans<<'\n';
                    return;
                }
                it--;
                int ans=*it+2*k*res;
                while(ans<maxn) ans+=2*k;
                cout<<ans<<'\n';
                //cout<<*it+2*k*res<<'\n';
                return;
            }
        }
    }
    cout<<-1<<'\n';
    
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
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<bool> b(n+1);
    vector<int> suf(n+1),r(n+1),pre(n+1),l(n+1);
    for(int i=n;i>=1;i--){
        suf[i]=a[i];
        r[i]=i;
        int id=i+1;
        while(id<=n&&suf[i]>=a[id]){
            suf[i]+=suf[id];
            id=r[id];
        }
        r[i]=id;
    }
    for(int i=1;i<=n;i++){
        pre[i]=a[i];
        l[i]=i;
        int id=i-1;
        while(id>=1&&pre[i]>=a[id]){
            pre[i]+=pre[id];
            id=l[id];
        }
        l[i]=id;
    }
    //for(int i=1;i<=n;i++) cout<<suf[i]<<" \n"[i==n];
    for(int i=1;i<=n;i++){
        if(b[i-1]){
            if(suf[i]>=a[i-1]){
                b[i]=1;
            }
            else b[i]=0;
        }
        else{
            int ll=i-1,rr=i+1;
            int res=a[i];
            while(ll>0||rr<=n){
                bool flag=1;
                if(ll>0&&a[ll]<=res){
                    res+=pre[ll];
                    ll=l[ll];
                    flag=0;
                }
                if(rr<=n&&a[rr]<=res){
                    res+=suf[rr];
                    rr=r[rr];
                    flag=0;
                }
                if(flag) break;
            }
            if(ll==0&&rr==n+1){
                b[i]=1;
            }
            else{
                b[i]=0;
                i=rr-1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=b[i];
    }
    cout<<ans<<'\n';
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
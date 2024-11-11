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
    vector<int> a(n+1),b(n+1),c(n+1);
    for(int i=1;i<=n;i++) cin>>a[i],c[i]=a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(c.begin()+1,c.end());
    //for(int i=1;i<=n;i++){
        //cout<<c[i]<<" \n"[i==n];
    //}
    int midden=c[(n+1)/2];
    int idmid=(n+1)/2;
    long long ans=0;
    int maxn=0,maxid=0;
    for(int i=1;i<=n;i++){
        long long res=a[i];
        if(b[i]){
            if(n%2){
                if(res<midden){
                    ans=max(ans,res+k+midden);
                }
                else{
                    ans=max(ans,res+k+c[idmid-1]);
                }
            }
            else{
                if(res<=midden){
                    ans=max(ans,res+k+c[idmid+1]);
                }
                else{
                    ans=max(ans,res+k+midden);
                }
            }
        }
        else{
            if(maxn<a[i]){
                maxn=a[i];
                maxid=i;
            }
        }
    }
    int m=n-1;
    vector<pair<int,int> > d; 
    d.push_back({0,0});
    for(int i=1;i<=n;i++){
        if(i==maxid) continue;
        d.push_back({a[i],b[i]});
    }
    sort(d.begin()+1,d.end());
    int middid=(m+1)/2;
    int num=m-middid+1;
    auto check = [&] (int x) -> bool {
        int cnt=0;
        int res=0;
        for(int i=m;i>=1;i--){
            if(d[i].first>=x) {cnt++;continue;}
            if(cnt>=num) break;
            if(d[i].second){
                res+=x-d[i].first;
                cnt++;
            }
        }
        if(cnt>=num&&res<=k) return 1;
        else return 0;
    };
    int l=1,r=2e9;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid) ) l=mid;
        else r=mid-1;
    }
    ans=max(ans,maxn+l);
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
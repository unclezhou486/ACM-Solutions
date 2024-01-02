#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int n;
int a[N];

int k;

int find(int x){
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(a[mid]>x) r=mid-1;
        else l=mid;
    }
    return l;
}

bool check(int x){
    int res=0;
    for(int i=1;i<=n;i++){
        int id=find(x-a[i]);
        if(a[id]<=x-a[i]){
            res+=id;
            if(a[id]>=a[i]) res-=1;
        }
        //cout<<id<<' '<<res<<'\n';
    }
    //cout<<x<<' '<<res/2<<'\n';
    if(res/2<k) return 0;
    else return 1;
}


void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    cin>>k;
    int l=a[1]+a[2],r=a[n]+a[n-1];
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    //cout<<check(6)<<' '<<check(8)<<'\n';
    cout<<l<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
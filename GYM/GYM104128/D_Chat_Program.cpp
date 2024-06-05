#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    long long m,c,d;
    cin>>n>>k>>m>>c>>d;
    vector<long long> a(n+5);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    auto check = [&] (long long x) -> bool {
        vector<int> pre(n+5,0);
        int res=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=x){
                res++;
                continue;
            }
            if(a[i]+(m-1)*d+c>=x){
                long long idx1=max(1ll,i-m+1);
                if(c+d*(i-idx1)+a[i]>=x) pre[idx1]+=1;
                else continue;
                long long ress=x-a[i]-c;
                if(ress<=0) {pre[i+1]-=1;continue;}
                long long idx2=ress/d;
                if(!(ress%d)) idx2-=1;
                idx2=max(1ll,i-idx2);
                pre[idx2]-=1;
            }
        }
        for(int i=1;i<=n;i++){
            pre[i]+=pre[i-1];
            if(pre[i]+res>=k) return 1;
        }
        return 0;
    };
    long long l=0,r=2e15;
    while(l<r){
        long long mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
}
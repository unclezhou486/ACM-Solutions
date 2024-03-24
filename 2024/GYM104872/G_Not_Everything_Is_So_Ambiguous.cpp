#include <bits/stdc++.h>
#define int long long 

using namespace std;

int n;

long long qmi(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    long long l=1,r=1e18;
    //long long rr=r;
    while(l<r){
        long long mid=(l+r)>>1;
        cout<<"? "<<mid<<endl;
        long long x;
        cin>>x;
        if(x>=n+1) r=mid;
        else l=mid+1;
    }
    long long d1=l;
    l=2,r=2023;
    while(l<r){
        long long mid=(l+r)>>1;
        bool fl=1;
        int res=1;
        for(int i=1;i<=n-1;i++){
            res*=mid;
            if(res>1000000000) {fl=0;break;}
        }
        if(fl==0) {r=mid-1;continue;}
        cout<<"? "<<d1+(mid-1)*qmi(mid,n)<<endl;
        long long x;
        cin>>x;
        if(x>=n+2) r=mid;
        else l=mid+1;
    }
    long long b=l;
    long long x=qmi(b,n)-d1;
    cout<<"! "<<x<<' '<<b<<endl;
}
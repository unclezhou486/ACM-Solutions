#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;
long long a[N];
long long b[N];

bool check(long long  x){
    for(int i=1;i<=n;i++){
        b[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(x>a[i]+b[i]){
            x+=a[i]/2;
            b[i+1]+=(a[i]+1)/2;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    long long l=1,r=1e18;
    while(l<r){
        long long mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';
}
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

long long ans;
long long a[N];
int n;
//long long x;
//int n,a[N];

long long res=0;
long long res1=0,res2=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(long long i=1;i<=n;i++){
        res+=i*i*a[i];
        res1+=a[i];
        res2+=i*a[i];
    }
    long long ans=res+res1-2*res2;
    for(long long x=2;x<=n;x++){
        ans=min(ans,res+x*x*res1-2*x*res2);
    }
    cout<<ans<<'\n';
}
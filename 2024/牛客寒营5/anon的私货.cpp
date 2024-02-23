#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int n;
int a[N];
int ans;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=a[n+1]=1e9;
    for(int i=1;i<=n+1;i++){
        int res=min(a[i],a[i-1])-1;
        ans+=res;
        a[i]-=res;
    }
    cout<<ans<<'\n';
}
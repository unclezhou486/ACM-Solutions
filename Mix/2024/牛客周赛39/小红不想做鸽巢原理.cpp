#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;


int n,k;
int ans;
int a[N];
signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];        
    }
    sort(a+1,a+1+n);
    k=sum%k;
    int res=0;
    for(int i=n;i>=1;i--){
        if(res>=k) break;
        res+=a[i];
        ans++;
    }
    cout<<ans<<'\n';
}
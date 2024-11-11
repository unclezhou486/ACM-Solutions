#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,a,sum;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        sum+=a;
    }
    int ans=0;
    for(int i=1;i<=sum;i++){
        if(sum/i<n) break;
        if((sum%i)==0){
            if(sum/i>=n){
                ans++;
            }
        }
    }
    if(n!=1)cout<<ans<<'\n';
    else cout<<1<<'\n';
}
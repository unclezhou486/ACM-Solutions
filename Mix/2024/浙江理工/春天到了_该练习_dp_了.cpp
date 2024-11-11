#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+10;


int a[N];
int s[N];
int s1[N];

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        s1[i]=s1[i-1]+(i*i);
    }
    int q;
    cin>>q;
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        int ans=s[r]-s[l-1];
        if(k){
            ans+=(s1[r-l+1]);
            if(k<=(r-l+1)){
                ans-=s1[(r-l+1)-k];
            }
        }
        cout<<ans<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
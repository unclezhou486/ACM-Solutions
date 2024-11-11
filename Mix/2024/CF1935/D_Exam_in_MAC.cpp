#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n,c;

void solve(){
    cin>>n>>c;
    //vector<int> v1,v2;
    int v1=0,v2=0;
    int res=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x%2)v1++;
        elsev2++;
        res+=x/2+1+(c-x+1);
    }
    int ans=(c+2)*(c+1)/2-(res-n);
    ans+=((v1*(v1-1)/2)+(v2*(v2-1)/2));
    cout<<ans<<'\n';
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
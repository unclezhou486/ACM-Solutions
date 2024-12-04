#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    long long n;
    cin>>n;
    vector<long long> vec1,vec2;
    for(int i=1;i<=n/i;i++){
        if(n%i==0) vec1.push_back(i),vec2.push_back(n/i);
    }
    for(int i=vec2.size()-1;i>=0;i--){
        vec1.push_back(vec2[i]);
    }
    long long res=0;
    long long ans=0;
    for(auto x:vec1){
        int ress=0;
        if(res==0) ress=0;
        else ress=n/res;
        ans+=(ress*(x-res));
        res=x;
    }
    ans+=1;
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
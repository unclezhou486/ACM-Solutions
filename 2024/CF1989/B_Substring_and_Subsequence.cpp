#include <bits/stdc++.h>

using namespace std;

void solve(){
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    int ans=1000;
    for(int i=0;i<m;i++){
        int res=m;
        int id=i;
        for(int j=0;j<n;j++){
            if(b[id]==a[j]&&id<m){
                id++;continue;
            }
            res++;
        }
        ans=min(ans,res);
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int a,b,l;
    cin>>a>>b>>l;
    set<int> se;
    int res1=1;
    for(int x=0;x<=20;x++){
        int res2=1;
        for(int y=0;y<=20;y++){
            int res=res1*res2;
            if(res>l) break;
            if(l%res==0){
                se.insert(l/res);
            }
            res2*=b;
            if(res2>l) break;
        }
        res1*=a;
        if(res1>l) break;
    }
    cout<<se.size()<<'\n';
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
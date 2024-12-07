#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    int res=0,time=0;
    for(int i=1;i<=n;i++){
        int t,v;
        cin>>t>>v;
        res=max(0,res-(t-time));
        res+=v;
        time=t;
    }
    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    solve();
    return 0;
}
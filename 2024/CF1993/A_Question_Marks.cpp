#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(5,0);
    for(int i=1;i<=4*n;i++){
        char ch;
        cin>>ch;
        if(ch=='?') continue;
        a[ch-'A'+1]+=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        ans+=min(n,a[i]);
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
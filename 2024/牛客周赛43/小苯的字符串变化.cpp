#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> a(n+1);
    vector<int> b(n+1);
    for(int i=0;i<n;i++){
        if(s[i]>='a') a[i+1]++;
        else b[i+1]++; 
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        b[n-i]+=b[n-i+1];
    }
    int ans=n;
    for(int i=1;i<n;i++){
        ans=min(ans,a[i]+b[i+1]);
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
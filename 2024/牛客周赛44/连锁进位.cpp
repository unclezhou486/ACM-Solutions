#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int x=0;
    int ans=0;
    for(int i=0;i<s.size()-1;i++){
        x/=10;
        x+=s[i]-'0';
        if(x&&x<10){
            ans+=(10-x);
            x=10;
        }
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
#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    if(s[0]>'Z'){
        cout<<"No\n";
        return;
    }
    for(int i=1;i<n;i++){
        if(s[i]<='Z'){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
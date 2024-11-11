#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n%2){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        char a='A';
        for(int i=1;i<=n/2;i++){
            cout<<a<<a;
            if(a=='A') a='B';
            else a='A';
        }
        cout<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
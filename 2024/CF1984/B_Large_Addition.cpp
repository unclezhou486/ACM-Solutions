#include <bits/stdc++.h>

using namespace std;

//5 5 10
//9 9 18

void solve(){
    long long x;
    cin>>x;
    while(x>0){
        int res=x%10;
        //cout<<x<<' '<<res<<'\n';
        x/=10;
        if(res<=8) x-=1;
        else{
            cout<<"NO\n";
            return;
        }
    }
    if(x<0) cout<<"NO\n";
    else cout<<"YES\n";
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
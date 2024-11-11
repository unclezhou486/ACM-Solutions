#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int res=0;
    int ans=0;
    res=a+b+c;
    if(res%2){
        cout<<-1<<'\n';
        return ;
    }
    while(a){
        if(b>=c){
            b-=1;
            a-=1;
            ans++;
        }
        else{
            c-=1;
            a-=1;
            ans++;
        }
    }
    ans+=min(b,c);
    cout<<ans<<'\n';
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
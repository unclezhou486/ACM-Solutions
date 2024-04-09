#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long x,y,z;
    cin>>x>>y>>z;
    long long  ans=0;
    //ans+=x;
    long long res=(y-1)/3*3;
    if(res<y) res+=3;
    if(y+z<res){
        cout<<-1<<'\n';
    }
    else{
        y+=z;
        ans=x;
        ans+=y/3;
        if(y%3)ans++;
        cout<<ans<<'\n';
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

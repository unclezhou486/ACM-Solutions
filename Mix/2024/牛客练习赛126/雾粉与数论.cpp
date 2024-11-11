#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

void solve(){
    long long n;
    cin>>n;
    long long n1,n2;
    if(n%2){
        n1=n,n2=n-1;
    }
    else{
        n2=n,n1=n-1;
    }
    long long res=(n1+1)/2;
    res*=res;
    res%=mod;
    long long ans=res;
    res=n2/2;
    res=(1+res)*res/2;
    res%=mod;
    ans+=res;
    ans%=mod;
    cout<<ans-1<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
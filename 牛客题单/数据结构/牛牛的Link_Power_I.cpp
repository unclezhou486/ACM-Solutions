#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int mod=1e9+7;
long long n;
char c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    long long res=0;
    long long cnt=0;
    long long ans=0;
    for(long long  i=1;i<=n;i++){
        cin>>c;
        if(c=='1'){
            ans+=i*cnt-(res);
            res+=i;
            cnt++;
            ans%=mod;
        }
    }
    cout<<ans<<'\n';
}
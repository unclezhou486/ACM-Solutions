#include <bits/stdc++.h>

using namespace std;

const int mod=998244353;

char c;

long long ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ans=1;
    long long res=1;
    while(cin>>c){
        ans*=3;
        if(c=='0'){
            res<<=1;
            res%=mod;
            ans=ans-res+mod;
        }
        ans%=mod;
    }
    cout<<ans<<'\n';
}
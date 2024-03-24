#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int N=1e5+10;

const int mod=1e9+7;

int n;

int a[N];

int res1,res2,res3;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if((a[i]%3)==1) res1++;
        else if((a[i]%3)==2) res2++;
        else res3++;
    }
    long long ans=0;
    if(res1==res2+2||res1+2==res2||res1==res2+1||res1+1==res2||(res1==0&&res2<=2)||(res2==0&&res1<=2)){
        long long res=1;
        for(int i=1;i<=res1;i++){
            res=res*i;
            res%=mod;
        }
        ans=res;
        res=1;
        for(int i=1;i<=res2;i++){
            res=res*i;
            res%=mod;
        }
        ans*=res;
        ans%=mod;
        res=1;
        //cout<<ans<<'\n';
        for(int i=res1+res2;i<res1+res2+res3;i++){
            res*=i;
            res%=mod;
        }
        //cout<<res<<'\n';
        ans*=res;
        ans%=mod;
    }
    cout<<ans<<'\n';
}
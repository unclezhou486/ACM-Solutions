#include <bits/stdc++.h>
#define int long long 
using namespace std;

int a,l;

signed main(){
    int res=0;
    for(int i=1;i<=5;i++){
        cin>>a>>l;
        res+=a*l;
    }
    int n,f;
    cin>>n>>f;
    res/=5;
    res*=n;
    res/=f;
    cout<<res<<'\n';
}
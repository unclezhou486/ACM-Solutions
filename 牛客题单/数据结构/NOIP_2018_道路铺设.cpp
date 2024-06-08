#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
    }
    cout<<ans<<'\n';
}
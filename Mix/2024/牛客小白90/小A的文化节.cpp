#include <bits/stdc++.h>

using namespace std;

const int N=1e2+10;

int n,m;

int  a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        ans+=a[x];
    }
    cout<<ans<<'\n';
}
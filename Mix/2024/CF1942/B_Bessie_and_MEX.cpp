#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int a[N];
int p[N];

void solve(){
    int n;
    //int a[N];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int res=n;
    for(int i=n;i>=1;i--){
        p[i]=res-a[i];
        res=min(res,p[i]);
    }
    for(int i=1;i<=n;i++)cout<<p[i]<<' ';
    cout<<'\n';
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
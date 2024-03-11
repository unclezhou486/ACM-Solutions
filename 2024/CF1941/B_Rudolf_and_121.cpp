#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int a[N],b[N];

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]+=x;
        if(i<n-1&&a[i]>=0){
            a[i+1]-=2*a[i];
            a[i+2]-=a[i];a[i]=0;
        }
    }
    bool fl=1;
    //cout<<'\n';
    for(int i=1;i<=n;i++){
        //cout<<a[i]<<' ';
        if(a[i]) fl=0;
    }
    if(fl) cout<<"YES\n";
    else cout<<"NO\n";
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
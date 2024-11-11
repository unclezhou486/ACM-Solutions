#include <bits/stdc++.h>

using namespace std;

const int N=100;

int n;
int a[N];

void solve(){
    cin>>n;
    int st=-1,ed;
    for(int i=1;i<=n;i++){
        
        cin>>a[i];
        if(a[i]==1){
            if(st==-1) st=i;
            ed=i;
        }

    }
    int ans=0;
    for(int i=st;i<=ed;i++){
        if(!a[i]) ans++;
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}   
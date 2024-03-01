#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,a[N],b[N];
int c[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i],c[i]=0;
    bool fl=1;
    for(int i=1;i<=n;i++){
        if(c[a[i]]){
            if(c[a[i]]!=b[i]){
                fl=0;
                break;
            }
        }
        c[a[i]]=b[i];
    }
    if(fl) cout<<"Yes\n";
    else cout<<"No\n";
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
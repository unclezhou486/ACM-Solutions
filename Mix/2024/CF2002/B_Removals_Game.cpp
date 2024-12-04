#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    vector<int> c(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) c[i]=b[n-i+1];
    bool flag1=1;
    bool flag2=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]) flag1=0;
        if(a[i]!=c[i]) flag2=0;
    }
    if(flag1||flag2){
        cout<<"Bob\n";
    }
    else {
        cout<<"Alice\n";
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
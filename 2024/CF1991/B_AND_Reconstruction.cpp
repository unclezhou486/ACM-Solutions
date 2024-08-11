#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    //vector<iontt>
    for(int i=1;i<n;i++){
        cin>>b[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<30;j++){
            if((b[i]>>j)&1){
                a[i]|=(1<<j);
                a[i+1]|=(1<<j);
            }
        }
    }
    for(int i=1;i<n;i++){
        if((a[i]&a[i+1])!=b[i]){
            cout<<"-1\n";
            return;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" \n"[i==n];
    }
    return;
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
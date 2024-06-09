#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,f,k;
    cin>>n>>f>>k;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    int x=a[f];
    sort(a.begin()+1,a.begin()+1+n);
    reverse(a.begin()+1,a.begin()+1+n);
    if(a[k]>x){
        cout<<"NO\n";
    }
    else if(a[k]<x){
        cout<<"YES\n";
    }
    else{
        if(a[k]==a[k+1]){
            cout<<"MAYBE\n";
        }
        else{
            cout<<"YES\n";
        }
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
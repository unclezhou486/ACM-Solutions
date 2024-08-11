#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    int ji,ou;
    ji=ou=0;    
    vector<int> jiv;
    vector<int> ouv;
    for(int i=1;i<=n;i++) cin>>a[i];
    int maxnou=0,maxnji=0;
    int xiaoou=0;
    for(int i=1;i<=n;i++){
        if(a[i]%2) ji++,maxnji=max(maxnji,a[i]),jiv.push_back(a[i]);
        else ou++,maxnou=max(maxnou,a[i]),ouv.push_back(a[i]);
    }
    for(int i=1;i<=n;i++){
        if(!(a[i]%2)){
            if(a[i]<maxnji){
                xiaoou=max(a[i],xiaoou);
            }
        }
    }
    if(ou==n||ji==n){
        cout<<0<<'\n';
        return;
    }
    sort(jiv.begin(),jiv.end());
    int maxn=jiv[jiv.size()-1];
    sort(ouv.begin(),ouv.end());
    for(int i=0;i<ouv.size();i++){
        if(ouv[i]>maxn){
            cout<<ou+1<<'\n';
            return;
        }
        else{
            maxn=maxn+ouv[i];
        }
    }
    cout<<ou<<'\n';
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
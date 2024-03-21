#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),c(n);
    for(int i=0;i<n;i++){
        a[i]=i+1;
        c[i]=i/k+1;
    }
    int q=*max_element(c.begin(),c.end());
    for(int i=1;i<=q;i++){
        int l=find(c.begin(),c.end(),i)-c.begin();
        int r=c.rend()-find(c.rbegin(),c.rend(),i);
        int m=(l+r)>>1;
        reverse(a.begin()+l,a.begin()+m);
        reverse(a.begin()+m,a.begin()+r);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i==n-1];
    }
    cout<<q<<'\n';
    for(int i=0;i<n;i++){
            cout<<c[i]<<" \n"[i==n-1];
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
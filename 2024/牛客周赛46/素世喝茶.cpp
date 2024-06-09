#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    int maxn=0;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=x) maxn=max(maxn,a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i!=x){
            if(a[i]==maxn) ans++;
        }
    }
    cout<<ans<<'\n';
}
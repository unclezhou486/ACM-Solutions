#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    vector<int> cnt(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!cnt[a[i]]) res++;
        cnt[a[i]]++;
        if(i>k){
            cnt[a[i-k]]--;
            if(!cnt[a[i-k]]) res--;
        }
        if(res==k) ans++;
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
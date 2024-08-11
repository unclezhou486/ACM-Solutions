#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    int maxn=0;
    int minn=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
    vector<int> ans;
    while(maxn>minn){
        if(maxn==minn+1){
            cout<<-1<<'\n';
            return;
        }
        int mid=(maxn+minn)>>1;
        ans.push_back(mid);
        maxn=0,minn=1e9;
        for(int i=1;i<=n;i++){
            a[i]=abs(a[i]-mid);
            maxn=max(maxn,a[i]);
            minn=min(minn,a[i]);
        }
    }
    if(maxn){
        ans.push_back(maxn);
    }
    //cout<<"A:";
    //for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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
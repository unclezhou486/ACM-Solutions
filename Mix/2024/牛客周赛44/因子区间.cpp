#include <bits/stdc++.h>

using namespace std;

int change(int x){
    int res=1;
    for(int i=2;i<=x/i;i++){
        if(x%i) continue;
        int cnt=0;
        while(x%i==0){
            cnt++;
            x/=i;
        }
        res*=(cnt+1);
    }
    if(x!=1){
        res*=2;
    }
    return res;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    //vector<int> b(n);
    vector<int> b(n+1);
    vector<vector<int> > pre(100,vector<int>(n+1));
    map<int,int> ma;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int res=change(a[i]);
        if(ma.count(res)){
            pre[ma[res]][i]+=1;
        }
        else{
            ma[res]=++cnt;
            pre[cnt][i]+=1;
        }
    }
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=n;j++){
            pre[i][j]+=pre[i][j-1];
        }
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        long long ans=0;
        for(int i=1;i<=cnt;i++){
            long long res=pre[i][r]-pre[i][l-1];
            ans+=res*(res-1)/2;
        }
        cout<<ans<<'\n';
    }
    //int cnt=0;
    //for(int i=1;i<=200000;i++){
    //    if(ma.count(change(i))) continue;
    //    ma[change(i)]=1;
    //    cnt++;
    //}
    //cout<<cnt<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
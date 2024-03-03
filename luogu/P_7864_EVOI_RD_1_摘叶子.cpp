#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;



int dis[N],cnt[N],n;
vector<vector<int> > ne(N);
void dfs(int x){
    if(cnt[x]>=2) dis[x]=0;
    for(auto v:ne[x]){
        dis[v]=dis[x]+1;
        dfs(v);
    }
}

void solve(){
    cin>>n;

    for(int i=1;i<=n;i++) cnt[i]=0,ne[i].clear();
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        ne[x].push_back(i);
        cnt[x]++;
    }
    dis[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++){
        if(!cnt[i]&&(dis[i]&1)){
            cout<<1<<'\n';
            return;
        }
    }
    cout<<0<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
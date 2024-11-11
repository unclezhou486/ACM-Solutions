#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int f[N];
bool v[N];

int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        f[i]=i;
        v[i]=0;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        f[find(u)]=find(v);
    }
    vector<int> vec[n+1];
    for(int i=1;i<=n;i++){
        vec[find(i)].push_back(i);
    }
    vector<int> q;
    for(int i=1;i<=n;i++){
        if(vec[i].size()) q.push_back(i);
    }
    if(n==1){
        cout<<"YES\n";
        cout<<0<<'\n';
        return;
    }
    cout<<"YES\n";
    cout<<n-1<<'\n';
    for(int i=0;i<vec[q[0]].size();i++){
        cout<<vec[q[1]][0]<<' '<<vec[q[0]][i]<<'\n';
    }
    for(int i=1;i<vec[q[1]].size();i++){
        cout<<vec[q[0]][0]<<' '<<vec[q[1]][i]<<'\n';
    }
    for(int i=2;i<q.size();i++){
        for(int j=0;j<vec[q[i]].size();j++){
            cout<<vec[q[0]][0]<<' '<<vec[q[i]][j]<<'\n';
        }
    }
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
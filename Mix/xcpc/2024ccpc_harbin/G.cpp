#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;

int n,m,k;
// int a[N];
bool a[N];
bool vis[N];

vector<int> adj[N];
vector<int> ans[N];
vector<int> anss;

void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        a[x]=1;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!a[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            int cnt=1;
            while(q.size()){
                vector<int> vecc;
                int x=q.front();
                q.pop();
                for(auto y:adj[x]){
                    if(vis[y]) continue;
                    vecc.push_back(y);
                    vis[y]=1;
                    cnt++;
                    if(!a[y]){
                        q.push(y);
                    }
                }
                if(vecc.size()){
                    anss.push_back(x);
                }
                ans[x]=vecc;
            }
            if(cnt==n){
                cout<<"Yes\n";
                cout<<anss.size()<<'\n';
                for(auto x:anss){
                    cout<<x<<' ';
                    cout<<ans[x].size()<<' ';
                    for(auto y:ans[x]){
                        cout<<y<<' ';
                    }
                    cout<<'\n';
                }
            }
            else{
                cout<<"No\n";
            }
            return;
        }
    }
    cout<<"No\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
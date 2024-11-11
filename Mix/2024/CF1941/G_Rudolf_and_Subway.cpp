#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,m;

struct node{
    int d,x,c;
};

void solve(){
    cin>>n>>m;
    vector<map<int,vector<int> > > ne(n+1);
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        ne[u][c].push_back(v);
        ne[v][c].push_back(u);
    }
    int ss,tt;
    cin>>ss>>tt;
    map<pair<int,int>,int> d;
    deque<node> q;
    q.push_back({0,ss,0});
    while(q.size()){
        auto [dd,x,c]=q.front();
        q.pop_front();
        if(d.count({x,c})) continue;
        d[{x,c}]=dd;
        if(c){
            q.push_front((node){dd,x,0});
            for(auto v:ne[x][c]){
                q.push_front((node){dd,v,c});
            }
        }
        else{
            for(auto [c,_]:ne[x]){
                q.push_back((node){dd+1,x,c});
            }
        }
    } 
    cout<<d[{tt,0}]<<'\n';
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
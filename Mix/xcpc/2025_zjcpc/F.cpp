#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> c(n+10);
	vector<vector<int> > adj(n+10),adjj(n+10);
	vector<vector<int> > ver(51);
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ver[c[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for(int i=1;i<=50;i++){
		queue<tuple<int,int,int> > q;
		vector<int> vis(n+10);
		for(auto x:ver[i]){
			q.emplace(x,x,1);
		}
		while(!q.empty()){
			auto [x,st,d]=q.front();
			q.pop();
			for(auto y:adj[x]){
				if(!vis[y]){
					vis[y]=st;
					q.emplace(y,st,d+1);
				}
				else if(vis[y]!=-1&&st!=vis[y]){
					vis[y]=-1;
					q.emplace(y,st,d+1);
				}
				if(c[y]==i&&st!=y&&d+1<=k){
					cout<<"NO\n";
					return;
				}
			}
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
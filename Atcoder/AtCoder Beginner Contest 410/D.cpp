#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int> > > adj(n+10);
	vector<vector<int> > vis(n+10,vector<int>(1025));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	queue<pair<int,int> > q;
	q.push({1,0});
	vis[1][0]=1;
	while(q.size()){
		auto [x,s]=q.front();
		q.pop();
		for(auto [y,w]:adj[x]){
			if(vis[y][s^w]) continue;
			vis[y][s^w]=1;
			q.push({y,s^w});
		}
	}
	int ans=-1;
	for(int i=0;i<=(1<<10);i++){
		if(vis[n][i]){
			ans=i;
			break;
		}
	}
	cout<<ans<<'\n';
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

#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int> > > adj(n+10);
	vector<map<int,int> > d(n+10);
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
		d[u][c]=d[v][c]=1e9;
	}
	vector<int> vis(n+10);
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > > ,greater<> > q;
	d[1][0]=0;
	q.push({d[1][0],{1,0}});
	while(q.size()){
		auto [dis,pos]=q.top();
		auto [x,c]=pos;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto &[col,dd]:d[x]){
			dd=min(dd,dis+((col==c)?0:1));
		}
		for(auto [y,w]:adj[x]){
			if(d[y][w]>d[x][w]){
				d[y][w]=d[x][w];
				q.push({d[y][w],{y,w}});
			}
		}
	}
	int ans=1e9;
	for(auto [col,val]:d[n]){
		ans=min(ans,val);
	}
	cout<<ans<<'\n';
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
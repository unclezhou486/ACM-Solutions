#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> vis(n+10);
	vector<vector<int> > adj(n+10);
	vector<int> deg(n+10);
	vector<int> vec;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		if(u&&!vis[u]){
			vis[u]=1;
			vec.push_back(u);
		}
		if(v&&!vis[v]){
			vis[v]=1;
			vec.push_back(v);
		}
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	sort(vec.begin(),vec.end(),greater<int>{});
	for(auto i:vec){
		// cout<<i<<" ";
		if(!deg[i]){
			cout<<"0\n";
			return;
		}
		for(auto y:adj[i]){
			if(y>i) continue;
			deg[y]--;
			if(y&&!deg[y]){
				cout<<"0\n";
				return;
			}
		}
	}
	cout<<1<<'\n';
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
#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	vector<vector<pair<int,int> > > adj(n+10);
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].emplace_back(v,w);
		adj[v].emplace_back(u,w);
	}
	long long ans=0;
	auto dfs = [&] (auto self,int x,int fa) -> void{
		for(auto [y,w]:adj[x]){
			if(y==fa) continue;
			self(self,y,x);
			ans+=1ll*w*abs(a[y]);
			a[x]+=a[y];
		}
	};
	dfs(dfs,1,1);
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
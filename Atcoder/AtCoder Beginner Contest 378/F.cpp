#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> deg(n+10);
	vector<long long> a(n+10);
	vector<vector<int> > adj(n+10);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	// for(int i=1;i<=n;i++) cout<<deg[i]<<" \n"[i==n];
	long long ans=0;
	auto dfs = [&](auto self,int x,int fa) -> void {
		for(auto y:adj[x]){
			if(y==fa) continue;
			self(self,y,x);
			if(deg[x]==3){
				ans+=a[x]*a[y];
				a[x]+=a[y];
			}
			if(deg[x]==2&&deg[y]!=2)ans+=a[y];
		}
		if(deg[x]==2) a[x]=1;
		else if(deg[x]!=3) a[x]=0;
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
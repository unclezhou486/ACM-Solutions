#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<vector<pair<int,int> > > adj(n+1);
	vector<int> f(n+1),fc(n+1);
	for(int i=1;i<n;i++){
		int u,v,c;
		cin>>u>>v>>c;
		adj[u].emplace_back(v,c);
		adj[v].emplace_back(u,c);
	} 
	long long ans=0;
	vector<map<int,long long> > sumc(n+1);
	auto dfs = [&](auto &&dfs,int x,int fa) -> void {
		f[x]=fa;
		if(x!=fa&&a[x]!=a[fa]) ans+=fc[x];
		for(auto [y,w]:adj[x]){
			if(y==fa) continue;
			fc[y]=w;
			sumc[x][a[y]]+=w;
			dfs(dfs,y,x);
		}
	};
	auto update = [&](int v,int x) -> void {
		if(a[v]==x) return; 
		if(v!=f[v]){
			if(a[v]!=a[f[v]]) ans-=fc[v];
			if(x!=a[f[v]]) ans+=fc[v];
			sumc[f[v]][a[v]]-=fc[v];
			sumc[f[v]][x]+=fc[v];
		}
		ans+=sumc[v][a[v]];
		ans-=sumc[v][x];
		a[v]=x;
	};
	dfs(dfs,1,1);
	// for(int i=1;i<=n;i++){
	// 	cout<<f[i]<<" \n"[i==n];
	// }
	while(q--){
		int v,x;
		cin>>v>>x;
		update(v,x);
		cout<<ans<<'\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
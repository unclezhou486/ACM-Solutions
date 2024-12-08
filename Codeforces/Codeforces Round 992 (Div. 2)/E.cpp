#include <bits/stdc++.h>
#define int long long

using namespace std;

constexpr int MOD=998244353;

void solve(){
	int n,q;
	cin>>n>>q;
	vector<vector<int> > adj(n+10);
	vector<int> deg(n+10);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		deg[u]++,deg[v]++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<vector<vector<int> > > f(n+10,vector<vector<int> >(n+10,vector<int>(2)));
	auto dfs=[&](auto self,int x,int fa) ->void{
		for(auto y:adj[x]){
			if(y==fa) continue;
			for(int j=0;j<=n;j++){
				f[y][j][0]=(deg[y]-1)*2+f[x][j][1]+1;
				if(j)f[y][j][0]=min(f[y][j][0],f[x][j-1][1]+1);
				f[y][j][1]=f[x][j][0]+1;
			}
			self(self,y,x);
		}
	};
	dfs(dfs,1,1);
	while(q--){
		int v,p;
		cin>>v>>p;
		cout<<f[v][p][1]%MOD<<'\n';
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
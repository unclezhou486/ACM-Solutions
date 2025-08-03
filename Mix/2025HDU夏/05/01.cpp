#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,q;
	cin>>n>>q;
	vector<long long> a(n+1),b(n+1);
	vector<vector<int> > adj(n+1),adjj(n+1);
	vector<int> f(n+1);
	for(int i=1;i<=n;i++) f[i]=i;
	vector<pair<long long,int> > aa(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		aa[i]={a[i],i};
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sort(aa.begin()+1,aa.end());
	auto find = [&] (auto &&find,int x) -> int{
		return f[x]==x?x:f[x]=find(find,f[x]);
	};
	int root=aa[n].second;
	vector<int> vis(n+1);
	for(int i=1;i<=n;i++){
		int x=aa[i].second;
		vis[x]=1;
		for(auto y:adj[x]){
			if(!vis[y]) continue;
			int v=find(find,y);
			adjj[v].push_back(x);
			adjj[x].push_back(v);
			f[v]=x;
		}
	}
	vector<vector<int> > fa(n+1,vector<int>(20));
	vector<vector<long long> >maxnum(n+1,vector<long long> (20,-1e18));
	vector<long long> bsum(n+1);
	auto dfs = [&](auto &&self,int x,int father) -> void {
		bsum[x]=b[x];
		for(auto y:adjj[x]){
			if(y==father) continue;
			self(self,y,x);
			bsum[x]+=bsum[y];
		}
	};
	auto dfss = [&](auto &&self,int x,int father) -> void{
		fa[x][0]=father;
		maxnum[x][0]=a[father]-(bsum[x]);
		for(int i=1;i<20;i++){
			fa[x][i]=fa[fa[x][i-1]][i-1];
			maxnum[x][i]=max(maxnum[x][i-1],maxnum[fa[x][i-1]][i-1]);
		}
		for(auto y:adjj[x]){
			if(y==father) continue;
			self(self,y,x);
		}
	};

	dfs(dfs,root,root);
	dfss(dfss,root,root);

	for(int i=1;i<=q;i++){
		int x;
		long long y;
		cin>>x>>y;
		if(y<a[x]){
			cout<<y<<'\n';
		}
		else{
			int xx=x;
			for(int i=19;i>=0;i--){
				if(y>=maxnum[xx][i]) xx=fa[xx][i];
			}
			cout<<bsum[xx]+y<<'\n';
		}
	}

}

/*
1
3 1
1 1 1
2 2 2
1 2
2 3
1 1


*/

//sum[x]+y-a[f[x]]>=0
//y >= a[f[x]]-sum[x]  

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
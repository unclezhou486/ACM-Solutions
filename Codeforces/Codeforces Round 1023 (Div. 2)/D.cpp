#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<vector<int> > adj(n+10);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(n+10);
	vector<int> f(n+10);
	auto dfs = [&] (auto self,int x,int fa) -> pair<int,int> {
		pair<int,int> res={1,x};
		f[x]=fa;
		for(auto y:adj[x]){
			if(y==fa||vis[y]) continue;
			auto ress=self(self,y,x);
			ress.first+=1;
			if(ress>res){
				res=ress;
			}
		}
		return res;
	};
	vector<tuple<int,int,int> > vec;
	int cnt=0;
	while(cnt!=n){
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				auto [d,j]=dfs(dfs,i,-1);
				auto [dd,k]=dfs(dfs,j,-1);
				vec.emplace_back(dd,max(j,k),min(j,k));
				while(k!=-1){
					vis[k]=1;
					k=f[k];
					cnt++;
				}
			}
		}
	}
	sort(vec.begin(),vec.end(),greater<tuple<int,int,int>>{});
	for(auto [d,j,k]:vec){
		cout<<d<<' '<<j<<' '<<k<<' ';
	}
	cout<<'\n';
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

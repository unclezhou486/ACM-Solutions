#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	// vector<set<int> > se(n+10);
	vector<vector<int> > adj(n+10);
	int ans=0;
	int maxx=0;
	int ansu=-1,ansv=-1;
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		// se[u].insert(v);
		// se[v].insert(u);
		adj[u].push_back(v);
		adj[v].push_back(u);
		ans+=w;
		if(w>=maxx){
			maxx=w;
			ansu=u;
			ansv=v;
		}
	}
	for(auto x:adj[ansu]){
		if(x==ansv) continue;
		else{
			cout<<x<<' '<<ansv<<' '<<0<<'\n';
			return;
		}
	}
	for(auto x:adj[ansv]){
		if(x==ansu) continue;
		else{
			cout<<x<<' '<<ansu<<' '<<0<<'\n';
			return;
		}
	}
	// if(se[ansu].size()==n-1){
	// 	for(int i=1;i<=n;i++){
	// 		if(!se[ansv].count(i)&&i!=ansv){
	// 			cout<<ansv<<' '<<i<<' '<<ans-maxx<<'\n';
	// 			return;
	// 		}
	// 	}
	// }
	// else{
	// 	for(int i=1;i<=n;i++){
	// 		if(!se[ansu].count(i)&&i!=ansu){
	// 			cout<<ansu<<' '<<i<<' '<<ans-maxx<<'\n';
	// 			return;
	// 		}
	// 	}
	// }
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
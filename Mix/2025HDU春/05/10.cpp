#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<vector<pair<int,int> > > adj(n+10);
	vector<int> dis(n+10);
	vector<int> vis(n+10);
	int cnt0=0,cnt1=0;
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		w%=2;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	} 
	queue<int> qu;
	qu.push(1);
	dis[1]=0;
	vis[1]=0;
	while(qu.size()){
		int x=qu.front();
		qu.pop();
		for(auto [y,w]:adj[x]){
			if(vis[y]) continue;
			vis[y]=1;
			dis[y]=dis[x]+w;
			qu.push(y);
		}
	}
	for(int i=1;i<=n;i++){
		if(dis[i]%2) cnt1++;
		else cnt0++;
	}
	cout<<1ll*cnt1*cnt1*cnt1+1ll*cnt0*cnt0*cnt0<<'\n';
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
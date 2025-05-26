#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m,x;
	cin>>n>>m>>x;
	vector<int> a(n+10);
	vector<vector<int> > vec(n+10);
	vector<vector<pair<int,int> > > adj(2*n+10);
	vector<vector<long long> > dis(2*n+10,vector<long long>(3,1e18));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vec[a[i]].push_back(i);
	}
	int tot=n;
	for(int i=1;i<=n;i++){
		if(vec[i].empty()) continue;
		tot++;
		for(auto y:vec[i]){
			adj[y].push_back({tot,0});
			adj[tot].push_back({y,x});
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int> > ,greater<> >q;
	dis[1][0]=0;
	q.push({dis[1][0],1,0});
	while(q.size()){
		auto [d,x,op]=q.top();
		q.pop();
		for(auto [y,w]:adj[x]){
			int opp=op;
			if(w){
				opp=(op+1)%3;
			}
			if(dis[y][opp]>dis[x][op]+w){
				dis[y][opp]=dis[x][op]+w;
				q.push({dis[y][opp],y,opp});
			}
		}
	}
	if(dis[n][0]!=1e18){
		cout<<dis[n][0]<<'\n';
	}
	else{
		cout<<-1<<'\n';
	}
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
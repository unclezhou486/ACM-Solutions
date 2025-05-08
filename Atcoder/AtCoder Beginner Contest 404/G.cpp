#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int> > > adj(n+10);
	for(int i=1;i<=m;i++){
		int l,r,s;
		cin>>l>>r>>s;
/*
pre[r]-pre[l-1]<=s
pre[r]-pre[l-1]>=s
pre[i]-pre[i-1]>=1

pre[r]<=pre[l-1]+s

pre[l-1]<=pre[r]-s

pre[i-1]<=pre[i]-1

*/	
		adj[l-1].emplace_back(r,s);
		adj[r].emplace_back(l-1,-s);
	}
	for(int i=1;i<=n;i++){
		adj[i].emplace_back(i-1,-1);
	}
	vector<long long> dis(n+10,1e18);
	vector<int> vis(n+10),cnt(n+10);
	for(int i=0;i<=n;i++){
		adj[n+1].emplace_back(i,0);
	}
	dis[n+1]=0;
	queue<int> q;
	q.push(n+1);
	cnt[n+1]++;
	vis[n+1]=1;
	while(q.size()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(auto [y,w]:adj[x]){
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				if(!vis[y]){
					vis[y]=1;
					cnt[y]++;
					q.push(y);
					if(cnt[y]==n+2){
						// for(int i=0;i<=n;i++){
						// 	cout<<cnt[i]<<" \n"[i==n];
						// }
						cout<<-1<<'\n';
						return;
					}
				}
			}
		}
	}
	// for(int i=0;i<=n;i++){
	// 	cout<<dis[i]<<" \n"[i==n];
	// }
	cout<<dis[n]-dis[0]<<'\n';
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

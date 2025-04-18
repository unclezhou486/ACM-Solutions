#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int> > > adj(n+10);
	vector<vector<long long> > dis(n+10,vector<long long>(20,1e18) );
	vector<long long> d(n+10);
	vector<int> vis(n+10);
	vector<int> cnt2(n+10);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	cnt2[1]=1;
	for(int i=1;i<=n;i++){
		if((i<<1)<=n)cnt2[(i<<1)]=cnt2[i]+1;
		if(((i<<1)|1)<=n)cnt2[(i<<1)|1]=cnt2[i]+1;
	}
	for(int i=1;i<=n;i++){
		priority_queue<pair<long long,int>,vector<pair<long long,int> > ,greater<> > q;
		dis[i][cnt2[i]]=0;
		q.push({dis[i][cnt2[i]],i});
		while(q.size()){
			auto [distance,x]=q.top();
			q.pop();
			if(vis[x]==i) continue;
			vis[x]=i;
			for(auto [y,w]:adj[x]){
				if(y<i) continue;
				if(dis[y][cnt2[i]]>dis[x][cnt2[i]]+w){
					dis[y][cnt2[i]]=dis[x][cnt2[i]]+w;
					q.push({dis[y][cnt2[i]],y});
				}
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int s,t;
		cin>>s>>t;
		long long ans=1e18;
		int ss=s,tt=t;
		while(cnt2[ss]>cnt2[tt]) ss>>=1;
		while(cnt2[tt]>cnt2[ss]) tt>>=1;
		while(ss!=tt) ss>>=1,tt>>=1;
		int res=cnt2[ss];
		while(res){
			ans=min(ans,(dis[s][res]+dis[t][res]));
			res--;
		}
		if(ans==1e18){
			cout<<"-1\n";
		}
		else cout<<ans<<'\n';
	}
}

//11 110 111 100

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
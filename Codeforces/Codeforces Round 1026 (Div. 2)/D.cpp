#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> b(n+10);
	vector<vector<pair<int,int> > >adj(n+10);
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].emplace_back(v,w);
	}
	auto check = [&](int xx) -> bool{
		vector<long long> maxn(n+10,-1);
		priority_queue<int,vector<int>,greater<> > q;
		vector<int> viss(n+10);
		q.push(1);
		viss[1]=1;
		maxn[1]=0;
		while(q.size()){
			int x=q.top();
			q.pop();
			for(auto [y,w]:adj[x]){
				if(w>xx) continue;
				if(maxn[x]+b[x]<w) continue;
				maxn[y]=max(maxn[y],maxn[x]+b[x]);
				if(!viss[y]){
					q.push(y);
					viss[y]=1;
				}
			}
		}
		// cout<<maxn[n]<<'\n';
		if(maxn[n]==-1) return 0;
		else return 1;
	};
	int l=0,r=1e9+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	// check(4);		
	if(l==1e9+1){
		cout<<-1<<'\n';
	}
	else{
		cout<<l<<'\n';
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

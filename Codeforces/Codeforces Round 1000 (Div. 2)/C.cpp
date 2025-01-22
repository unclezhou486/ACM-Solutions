#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> deg(n+10);
	vector<vector<int> > adj(n+10);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]+=1;
		deg[v]+=1;
	}
	int ans=1;
	priority_queue<pair<int,int>> q;
	int maxn,maxcnt;
	maxn=0,maxcnt=0;
	for(int i=1;i<=n;i++){
		q.push({deg[i],i});
		if(deg[i]>maxn){
			maxn=deg[i];
			maxcnt=1;
		}
		else if(deg[i]==maxn){
			maxcnt+=1;
		}
	}
	if(maxcnt>2){
		ans=1+2*(maxn-1);
	}
	else{
		auto [w,x]=q.top();
		q.pop();
		for(auto y:adj[x]){
			deg[y]-=1;
		}
		ans+=w-1;
		while(deg[q.top().second]!=q.top().first){
			auto [w,x]=q.top();
			q.pop();
			q.push({deg[x],x});
		}
		auto [ww,xx]=q.top();
		q.pop();
		ans+=ww-1;
	}
	cout<<ans<<'\n';
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
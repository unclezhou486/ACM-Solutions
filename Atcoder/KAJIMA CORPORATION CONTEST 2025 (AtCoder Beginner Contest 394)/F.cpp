#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<vector<int> > adj(n+10);
	vector<int> dp(n+10);
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans=0;
	auto dfs = [&](auto self,int x,int fa) -> void {
		dp[x]=1;
		vector<int> vec;
		for(auto y:adj[x]){
			if(y==fa) continue;
			self(self,y,x);
			vec.push_back(dp[y]);
		}
		// if(vec.size())
		sort(vec.begin(),vec.end());
		reverse(vec.begin(),vec.end());
		if(vec.size()) ans=max(ans,vec[0]+1);
		if(vec.size()>=4) ans=max(ans,vec[0]+vec[1]+vec[2]+vec[3]+1);
		if(vec.size()>=3) dp[x]=max(dp[x],vec[0]+vec[1]+vec[2]+1);
		return;
	};
	dfs(dfs,1,0);
	if(ans<=4) cout<<-1<<'\n';
	else cout<<ans<<'\n';
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
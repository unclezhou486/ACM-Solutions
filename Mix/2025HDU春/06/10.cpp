#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<vector<int> > adj(n+10);
	vector<int> siz(n+10);
	vector<vector<long long> > res(n+10);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;	
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long long ans=0;
	auto dfs = [&](auto self,int x,int fa) -> void{
		siz[x]=1;
		for(auto y:adj[x]){
			if(y==fa) continue;
			self(self,y,x);
			siz[x]+=siz[y];
			res[x].push_back(siz[y]);
		}
	};
	dfs(dfs,1,1);
	vector<long long> dp(4);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) dp[j]=0;
		dp[0]=1;
		long long sum=1;
		long long sumres=0;
		for(auto x:res[i]){
			for(int j=3;j>=1;j--){
				dp[j]+=(dp[j-1]*x);
			}
			sum+=x;
			sumres+=(x*x);
		}
		sum=n-sum;
		if(sum){
			for(int j=3;j>=1;j--){
				dp[j]+=dp[j-1]*sum;
			}
			sumres+=(sum*sum);
		}
		ans=1ll*n*n-sumres+3*dp[3]+dp[2];
		cout<<ans<<" \n"[i==n];
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
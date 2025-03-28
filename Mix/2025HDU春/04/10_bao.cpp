#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,c;
	cin>>n>>c;
	vector<int> a(n+10);
	// map<pair<int,int>>
	vector<map<int,int> > ma(c+10);
	vector<int> dp(c+10),ans(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		ma[u][v]=1;
		ma[v][u]=1;
	}
	dp[a[1]]=1;
	ans[1]=1;
	for(int i=2;i<=n;i++){
		long long res=0;
		for(auto [x,y]:ma[a[i]]){
			res+=dp[x];
		}
		ans[i]=res;
		dp[a[i]]+=res;
	}
	cout<<ans[n]<<'\n';
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
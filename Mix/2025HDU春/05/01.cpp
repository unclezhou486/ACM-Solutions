#include <bits/stdc++.h>

using namespace std;

constexpr int mod=1e9+7;

void solve(){
	int n,m,v;
	cin>>n>>m>>v;
	vector<int> g(n+10);
	vector<vector<int> > dp(m+10,vector<int>(v+10) );
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=v;k>=g[i];k--){
				dp[j][k]+=dp[j-1][k-g[i]];
				dp[j][k]%=mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=v;i++){
		ans+=dp[m][i];
		ans%=mod;
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
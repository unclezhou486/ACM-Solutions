#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m,x;
	cin>>n>>m>>x;
	vector<vector<long long> > s(n+10,vector<long long>(m+10)),a(n+10,vector<long long>(m+10));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j]>>a[i][j];
			s[i][j]+=s[i][j-1];
		}
		for(int j=m-1;j>=1;j--){
			a[i][j]+=a[i][j+1];
		}
	}
	vector<vector<long long> > dp(n+10,vector<long long>(x+10,1e18) );
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++){
			dp[i][j]=dp[i-1][j]+a[i][1];
		}
		for(int j=1;j<=m;j++){
			for(int k=x;k>=s[i][j];k--){
				dp[i][k]=min(dp[i][k],dp[i-1][k-s[i][j]]+a[i][j+1]);
			}
		}
	}
	long long ans=1e18;
	// for(int i=1;i<=n;i++){
	// 	for(int j=0;j<=x;j++){
	// 		cout<<dp[i][j]<<" \n"[j==x];
	// 	}
	// }
	for(int i=0;i<=x;i++){
		ans=min(ans,dp[n][i]);
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
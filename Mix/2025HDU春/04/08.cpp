#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> a(n+10,vector<int> (k+10));
	vector<vector<long long>> dp(n+10,vector<long long>(k+10));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
		}
	}	
	vector<long long> maxn(k+10);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			dp[i][j]=max(dp[i][j],maxn[j]+a[i][j]);
			maxn[j]=max(dp[i][j],maxn[j]);
			maxn[j]=max(maxn[j],maxn[j-1]);
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=k;j++){
	// 		cout<<dp[i][j]<<" \n"[j==k];
	// 	}
	// }

	cout<<dp[n][k]<<'\n';
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
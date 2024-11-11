#include <bits/stdc++.h>

using namespace std;

constexpr int INF=1e9;

void solve(){
	int n;
	cin>>n;
	vector<vector<int> > dp(n+10,vector<int> (2,INF));
	dp[0][0]=1;
	dp[0][1]=0;
	for(int i=1;i<n;i++){
		char ch;
		cin>>ch;
		if(ch=='1'){
			dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+1);
			dp[i][1]=min(dp[i-1][0],dp[i][1]);
		}
		else{
			dp[i][0]=min(dp[i-1][0]+1,dp[i][0]);
			dp[i][1]=min(min(dp[i-1][1],dp[i-1][0]),dp[i][1]);
		}
	}
	// for(int i=1;i<n;i++){
		// cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
	// }
	cout<<min(dp[n-1][0],dp[n-1][1])<<'\n';
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